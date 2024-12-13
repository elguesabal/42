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

/// @brief METODO Q COMECA A MONITORAR TODOS OS FDS USANDO poll() E GERENCIA QUAL O DESTINO DO DADO RECEBIDO (SE E UM NOVO CLIENTE, UM CLIENTE DESCONECTANDO)
void Server::listener(void) {
	while (true) {
		int ret = poll(this->fds.data(), this->fds.size(), -1);
		if (ret == -1) {
			std::cout << "erro no poll" << std::endl;
			exit(1);
		} else if (this->fds[0].revents & POLLIN) {
			this->newClient();
		} else {
			for (unsigned int i = 1; i < this->fds.size(); i++) {
				if (this->fds[i].revents & POLLIN) {
					memset(this->bufferChar, 0, 1024);
					ssize_t bytes_received = recv(this->fds[i].fd, this->bufferChar, 1024, 0);
					if (bytes_received > 0) {
						this->newBuffer(this->clients[i - 1]);
					} else if (bytes_received == 0) {
						this->deleteClient(this->clients[i - 1]);
					} else if (bytes_received < 0) {
						std::cerr << "Erro ao receber mensagem" << std::endl;
					}
					break;
				}
			}
		}
	}
}

/// @brief CRIA UM NOVO CLIENTE E SALVA O FD NO VECTOR DE FDS E O CLIENTE NO VECTOR DE CLIENTES
void Server::newClient(void) {
    Client *newClient = new Client(*this);

	this->fds.push_back(newClient->pfd);
	this->clients.push_back(newClient);
}

/// @brief REMOVE UM CLIENTE DO FD NO VECTOR DE FDS E O CLIENTE NO VECTOR DE CLIENTES
void Server::deleteClient(Client *client) {
	unsigned int i = std::find(this->clients.begin(), this->clients.end(), client) - this->clients.begin() + 1;

	this->fds.erase(this->fds.begin() + i);
	delete this->clients[i - 1];
	this->clients.erase(this->clients.begin() + i - 1);
}

/// @brief FUNCAO Q ENCAMINHA COMO O BUFFER RECEBIDO POR UM CLIENTE ESPECIFICO VAI SER TRATADO
/// @param client REFERENCIA Q CONTEM AS INFORMACOES DO CLIENTE
void Server::newBuffer(Client *client) {
	// if (client->auth == false) { // OS CLIENTES IRC NAO FUNCIONAM ASSIM
	// 	this->authentication(client);
	// } else {
	// 	for (unsigned int i = 1; i < this->fds.size(); i++) {
	// 		if (this->fds[i].fd != client->pfd.fd) {
	// 			send(this->fds[i].fd, this->bufferStr.c_str(), this->bufferStr.size(), 0);
	// 		}
	// 	}
	// }

	// this->bufferStr = this->bufferChar;
	splitMessage(*this);
	// this->splitMessage();

	for (unsigned int i = 0; i < this->bufferStrs.size(); i++) {
		this->bufferStr = this->bufferStrs[i]; // AKI EU TO SEMPRE ATUALIZANDO this->bufferStr PARA NAO PRECISAR FICAR PASSANDO COMO PARAMETRO PQ NAO FAZER COM INDECE E CLIENTE?

		if (this->bufferStr == "CAP LS 302\r\n") { // this->bufferStr NAO RECEBE MAIS \r POR CAUSA DE splitMessage();
			std::string res = ":" + this->getIp() + " CAP * LS\r\n";
			send(client->getFd(), res.c_str(), res.size(), 0);
		} else if (this->bufferStr.find("PASS ") == 0) {
			// std::cout << "verificar a senha" << std::endl;
			this->PASS(client);
		} else {
			// send(client->getFd(), "/JOIN aaa\r\n", 11, 0);
		}
	}

	//  else if (this->bufferStrs.size() == 3) { // FALTA MAIS VERIFICACOES
	// 		authentication(client);
	// }
	// TENHO Q VER COMO VAI FICAR COM A POSSIBILIDADE DE TER MAIS DE UM COMANDO NA MESMA COMUNICACAO (USAR UM VECTOR COM STRINGS)
}

/// @brief FUNCAO Q LIDA COM A VALIDACAO DO PASS NICK E USER
/// @param client REFERENCIA Q CONTEM AS INFORMACOES DO CLIENTE
void Server::authentication(Client *client) { // ESSA FUNCAO VAI MORRER PARA NASCER PASS() NICK() E USER()
	// this->bufferStr.erase(this->bufferStr.size() - 1);
	// if (this->bufferStr == this->password) {
	// 	client->auth = true;
	// 	send(client->pfd.fd, "Bem vindo ao servidor!\n", 23, 0);
	// } else {
	// 	if (client->password_attempts > 1) {
	// 		send(client->pfd.fd, "Limite de tentativas excedidas. Aguarde e tente novamente mais tarde\n", 69, 0);
	// 		this->deleteClient(client);
	// 	} else {
	// 		send(client->pfd.fd, "Senha incorreta! Digite novamente: ", 35, 0);
	// 		client->password_attempts++;
	// 	}
	// }


	if (this->bufferStrs[0] != "PASS a") { // AKI EU CONSEGUI O RESULTADO CORRETO POREM ACREDITO Q VOU TER Q REFATORAR O CODIGO PARA PROCESSAR OS COMANDOS SEPARADAMENTE
		std::string res = ":" + this->getIp() + " 464 * :Senha errada\r\n";
		send(client->getFd(), res.c_str(), res.size(), 0);
		this->deleteClient(client);
	}
}

/// @brief FUNCAO Q LIDA COM A VALIDACAO DA SENHA
/// @param client REFERENCIA Q CONTEM AS INFORMACOES DO CLIENTE
void Server::PASS(Client *client) {
	if (this->bufferStr != ("PASS " + this->password)) { // AKI EU CONSEGUI O RESULTADO CORRETO POREM ACREDITO Q VOU TER Q REFATORAR O CODIGO PARA PROCESSAR OS COMANDOS SEPARADAMENTE
		std::string res = ":" + this->getIp() + " 464 * :Senha errada\r\n";
		send(client->getFd(), res.c_str(), res.size(), 0);
		this->deleteClient(client);
	}
}







/// @brief FUNCAO DE TESTE
/// @param signal SINAL RECEBIDO
// static void Server::teste(int signal) {
// 	if (signal == SIGINT) {
// 		std::cout << std::endl << "Fechando servidor...................." << std::endl;
// 		exit(0);
// 	}
// }