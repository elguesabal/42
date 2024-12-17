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
	// this->client = NULL; // NAO PRECISO INICIALIZAR PQ SEMPRE VAI SER ATUALIZADO AO RECEBER UMA NOVA MENSAGEM
	// this->index = 0; // NAO PRECISO INICIALIZAR PQ SEMPRE VAI SER ATUALIZADO AO RECEBER UMA NOVA MENSAGEM
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
	// unsigned int i = std::find(this->clients.begin(), this->clients.end(), this->client) - this->clients.begin() + 1;
	// this->fds.erase(this->fds.begin() + i);
	// delete this->clients[i - 1];
	// this->clients.erase(this->clients.begin() + i - 1);
	// NAO PRECISO MAIS CRIAR UM INDICE i CALCULANDO USANDO find() PQ ESTOU SALVANDO DENTRO DE this->index

	this->fds.erase(this->fds.begin() + this->index);
	this->nicks.erase(this->client->nick); // REMOVE O NICK DA LISTA DE NICKS EM USO
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
					this->index = i; // AKI EU ATUALIZO O index DA CLASSE Server
					this->client = this->clients[i - 1]; // AKI EU ATUALIZO O cliente DA CLASSE Server
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
		} else if (this->bufferStr.find("PASS ") == 0) {
			this->PASS(); // BELEZA EU MANDO UMA MENSAGEM DE SENHA ERRADA E EXCLUO O CLIENTE E FECHO O FD POREM AINDA EXECUTO OS COMANDOS NICK E USER Q VEM JUNTO
		} else if (this->bufferStr.find("NICK ") == 0) {
			this->NICK(); // PAREI AKI
		} else if (this->bufferStr.find("USER ") == 0) {
			std::cout << "caiu no user" << std::endl;
		} else {
			// send(client->getFd(), "/JOIN aaa\r\n", 11, 0);
			std::cout << "caiu no else" << std::endl;
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
	if (this->bufferStr.substr(5) != this->password) {
		std::string res = ":" + this->getIp() + " 464 * :Senha errada\r\n";
		send(this->client->getFd(), res.c_str(), res.size(), 0);
		this->deleteClient();
		this->bufferStrs.clear(); // INPEDE Q OS COMANDO NICK E USER SEJAM AXECUTADOS MESMO COM O CLIENTE FECHADO
	}
}

/// @brief FUNCAO RESPONSAVEL POR VERIFICAR SE O NICK ESTA DISPONIVEL SALVAR
void Server::NICK(void) {
	if (this->nicks.find(this->bufferStr.substr(5)) != this->nicks.end()) {
		std::cout << "nick em uso" << std::endl;
		// AINDA FALTA MANDAR A RESPOSTA PRO CLIENTE Q JA ESTA EM USO
	} else {
		std::cout << "nick livre" << std::endl;
		this->nicks.insert(this->bufferStr.substr(5));
		this->client->nick = this->bufferStr.substr(5);
	}
}