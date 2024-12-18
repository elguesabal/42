#include "header.h"

/// @brief CONSTRUTOR Q INICIALIZA O SERVIDOR
/// @param port PORTA EM Q O SERVIDOR ESTARA ABERTO
/// @param password SENHA Q O SERVIDOR ADOTARA
Server::Server(int port, char *password) {
	this->pfd.fd = socket(AF_INET, SOCK_STREAM, 0);
	if (this->pfd.fd == -1) {
		std::cerr << "Erro ao criar o socket" << std::endl;
		exit(1);
	}
	int opt = 1;
	if (setsockopt(this->pfd.fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
		std::cerr << "Erro ao definir opção de socket" << std::endl;
		exit(1);
	}
	this->server.sin_family = AF_INET;
	this->server.sin_addr.s_addr = INADDR_ANY;
	this->server.sin_port = htons(port);
	if (bind(this->pfd.fd, (struct sockaddr *)&this->server, sizeof(this->server)) == -1) {
		std::cerr << "Erro ao associar o socket ao endereço e porta" << std::endl;
		exit(1);
	}
	if (listen(this->pfd.fd, 5)) {
		std::cerr << "Erro ao colocar o socket em modo de escuta" << std::endl;
		close(this->pfd.fd);
		exit(1);
	}
	fcntl(this->pfd.fd, F_SETFL, O_NONBLOCK);
	this->pfd.events = POLLIN;
	this->fds.push_back(this->pfd);
	this->password = password;
	std::cout << "Servidor iniciado na porta: " << port << std::endl << "Senha: " << password << std::endl << std::endl;
}

Server::~Server(void) {
	// close(this->pfd.fd); SE EU USO CTRL+C ESSA BAGACA NAO E CHAMADA
}

/// @brief CRIA UM NOVO CLIENTE E SALVA O FD NO VECTOR DE FDS E O CLIENTE NO VECTOR DE CLIENTES
void Server::newClient(void) {
	Client *newClient = new Client(*this);

	this->fds.push_back(newClient->pfd);
	this->clients.push_back(newClient);
}

/// @brief REMOVE UM CLIENTE DO FD NO VECTOR DE FDS E O CLIENTE NO VECTOR DE CLIENTES
void Server::deleteClient(void) {
	this->fds.erase(this->fds.begin() + this->index);
	this->nickClient.erase(this->client->nick); // REMOVE O NICK DA LISTA DE NICKS EM USO
	delete this->client;
	this->clients.erase(this->clients.begin() + this->index - 1);
}

/// @brief METODO Q COMECA A MONITORAR TODOS OS FDS USANDO poll() E GERENCIA QUAL O DESTINO DO DADO RECEBIDO (SE E UM NOVO CLIENTE, UM CLIENTE DESCONECTANDO)
void Server::listener(void) {
	while (true) {
		int ret = poll(this->fds.data(), this->fds.size(), -1);
		if (ret == -1) {
			std::cout << "Erro no poll" << std::endl;
			exit(1);
		} else if (this->fds[0].revents & POLLIN) {
			this->newClient();
		} else {
			for (unsigned int i = 1; i < this->fds.size(); i++) {
				if (this->fds[i].revents & POLLIN) {
					this->index = i;
					this->client = this->clients[i - 1];
					memset(this->bufferChar, 0, 1024);
					ssize_t bytes_received = recv(this->fds[i].fd, this->bufferChar, 1024, 0);
					if (bytes_received > 0) {
						this->newBuffer();
					} else if (bytes_received == 0) {
						this->deleteClient();
					} else if (bytes_received < 0) {
						std::cerr << "Erro ao receber mensagem" << std::endl;
					}
					break;
				}
			}
		}
	}
}

/// @brief FUNCAO Q ENCAMINHA COMO O BUFFER RECEBIDO POR UM CLIENTE ESPECIFICO VAI SER TRATADO
void Server::newBuffer(void) {
	this->bufferStr = this->bufferChar;
	splitMessage(*this);

	for (unsigned int i = 0; i < this->bufferStrs.size(); i++) {
		this->bufferStr = this->bufferStrs[i]; // AKI EU TO SEMPRE ATUALIZANDO this->bufferStr PARA NAO PRECISAR FICAR PASSANDO COMO PARAMETRO PQ NAO FAZER COM INDECE E CLIENTE?

		if (this->bufferStr == "CAP LS 302") { // O CLIENTE MANDA UM "CAP END" ENTAO AINDA NAO VOU PROCURAR APENAS POR CAP
			this->CAP();
		} else if (this->bufferStr.find("PASS") == 0) {
			this->PASS(); // BELEZA EU MANDO UMA MENSAGEM DE SENHA ERRADA E EXCLUO O CLIENTE E FECHO O FD POREM AINDA EXECUTO OS COMANDOS NICK E USER Q VEM JUNTO
		} else if (this->bufferStr.find("NICK") == 0) {
			this->NICK();
		} else if (this->bufferStr.find("USER") == 0) {
			this->USER();
		} else {
			// send(client->getFd(), "/JOIN aaa\r\n", 11, 0);
			// std::cout << "caiu no else" << std::endl;
			// std::cout << "caiu no else: " << this->bufferStr << " i: " << i << std::endl;
		}
	}
}

/// @brief FUNCAO Q RESPONDE AO COMANDO "CAP"
void Server::CAP(void) {
	std::string res = ":" + this->getIp() + " CAP * LS\r\n";
	send(this->client->getFd(), res.c_str(), res.size(), 0);
}

/// @brief FUNCAO Q LIDA COM A VALIDACAO DA SENHA
void Server::PASS(void) {
	if (this->client->auth == true) {
		std::string res = ":" + this->getIp() + " " + ERR_ALREADYREGISTRED + " " + this->client->nick + " :Comando não autorizado (já registrado)\r\n"; // Unauthorized command (already registered)
		send(this->client->getFd(), res.c_str(), res.size(), 0);
	} else if (this->bufferStr.substr(5) != this->password) {
		std::string res = ":" + this->getIp() + " " + ERR_PASSWDMISMATCH + " * :Senha incorreta\r\n"; // Password incorrect
		send(this->client->getFd(), res.c_str(), res.size(), 0);
		this->deleteClient();
		this->bufferStrs.clear(); // INPEDE Q OS COMANDO NICK E USER SEJAM AXECUTADOS MESMO COM O CLIENTE FECHADO
	} else {
		this->client->auth = true;
	}
}

/// @brief FUNCAO RESPONSAVEL POR VERIFICAR SE O NICK ESTA DISPONIVEL SALVAR
void Server::NICK(void) {
	if (this->bufferStr.substr(5) == "") {
		// std::cout << "nao veio o nick" << std::endl;
		std::string res = ":" + this->getIp() + " " + ERR_NONICKNAMEGIVEN + " * :Nenhum apelido fornecido\r\n"; // No nickname given
		std::cout << res << std::endl;
		send(this->client->getFd(), res.c_str(), res.size(), 0);
	} else if (this->nickClient.find(this->bufferStr.substr(5)) != this->nickClient.end()) {
		// std::cout << "nick em uso" << std::endl;
		std::string res = ":" + this->getIp() + " " + ERR_NICKNAMEINUSE + " * " + this->bufferStr.substr(5) + " :O apelido já está em uso\r\n"; // Nickname is already in use
		send(this->client->getFd(), res.c_str(), res.size(), 0);
	} else {
		// std::cout << "nick livre" << std::endl;
		this->nickClient[this->bufferStr.substr(5)] = this->client;
		this->client->nick = this->bufferStr.substr(5);
	}



	// VERIFICA REGRAS PARA SENHA COMO NOME RESERVADOS E CARACTERES ESPECIAIS
}

/// @brief FUNCAO Q SALVA O USER
void Server::USER(void) {
	std::cout << "caiu no user" << std::endl;
}