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
	this->addCmds();
	std::time_t currentTime = std::time(0);
	this->time = std::localtime(&currentTime);
	std::cout << "Servidor iniciado na porta " << port << " as " << this->getTime() << " do dia " << this->getDate() << std::endl << "Senha: " << password << std::endl << std::endl;
}

/// @brief DESTRUTOR DA CLASSE
Server::~Server(void) {
	// LIBERAR A MEMORIA DO PONTEIRO time
	// PRECISO DELETAR TODOS OS CLIENTES
}

void Server::addCmds(void) {
	this->serverCommands["CAP"] = &Server::CAP;
	this->serverCommands["PASS"] = &Server::PASS;
	this->serverCommands["NICK"] = &Server::NICK;
	this->serverCommands["USER"] = &Server::USER;
	this->serverCommands["QUIT"] = &Server::QUIT;
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
	this->nickClient.erase(this->client->nick);
	this->cmds.clear();
	delete this->client;
	this->clients.erase(this->clients.begin() + this->index - 1);
}

/// @brief METODO Q COMECA A MONITORAR TODOS OS FDS USANDO poll() E GERENCIA QUAL O DESTINO DO DADO RECEBIDO (SE E UM NOVO CLIENTE, UM CLIENTE DESCONECTANDO)
void Server::listener(void) {
	// while (true) { // ACHO Q DA BOM USAR GOTO (POSSO ORGANIZAR MELHOR O CODIGO)
	// 	int ret = poll(this->fds.data(), this->fds.size(), -1);
	// 	if (ret == -1) {
	// 		std::cout << "Erro no poll" << std::endl;
	// 		exit(1);
	// 	} else if (this->fds[0].revents & POLLIN) {
	// 		this->newClient();
	// 	} else {
	// 		for (unsigned int i = 1; i < this->fds.size(); i++) {
	// 			if (this->fds[i].revents & POLLIN) {
	// 				this->index = i;
	// 				this->client = this->clients[i - 1];
	// 				memset(this->buffer, 0, 512);
	// 				ssize_t bytes_received = recv(this->fds[i].fd, this->buffer, 1024, 0); // TRATAR \n SOLTO
	// 				if (bytes_received > 0) {
	// 					this->newBuffer();
	// 				} else if (bytes_received == 0) {
	// 					this->deleteClient();
	// 				} else if (bytes_received < 0) {
	// 					std::cout << "Erro ao receber mensagem" << std::endl;
	// 				}
	// 				break;
	// 			}
	// 		}
	// 	}
	// }


	// USANDO O COMANDO GOTO
	newComand:
	int ret = poll(this->fds.data(), this->fds.size(), -1);

	if (ret == -1) {
		std::cout << "Erro no poll" << std::endl;
		// exit(1);
		close(this->pfd.fd); // TENHO Q ESTUDAR MAIS PARA ENTENDER QUANDO FECHAR E DEVO CRIAR UM METODO PARA DAR FREE NA MEMORIA DOS CLIENTES // SERA Q EXISTE ALGUM PROTOCOLO Q FALA SOBRE REINICIAR O SERVIDOR???
		return ; // ASSIM EU POSSO FAZER UM LOOP REINICIANDO O SERVIDOR
	}

	if (this->fds[0].revents & POLLIN) {
		this->newClient();
		goto newComand;
	}

	for (unsigned int i = 1; i < this->fds.size(); i++) {
		if (this->fds[i].revents & POLLIN) {
			this->index = i;
			this->client = this->clients[i - 1];
			memset(this->buffer, 0, 512);
			ssize_t bytes_received = recv(this->fds[i].fd, this->buffer, 1024, 0); // TRATAR \n SOLTO
			if (bytes_received > 0) {
				this->newBuffer();
			} else if (bytes_received == 0) {
				this->deleteClient();
			} else if (bytes_received < 0) {
				std::cout << "Erro ao receber mensagem" << std::endl;
			}
			goto newComand;
		}
	}
}

/// @brief METODO Q ENCAMINHA COMO O BUFFER RECEBIDO POR UM CLIENTE ESPECIFICO VAI SER TRATADO
void Server::newBuffer(void) {
	this->cmd = this->buffer;
	if (this->invalidLine()) {
		this->resClient("Quebra do protocolo IRC...");
		this->deleteClient();
		return ;
	}
	this->splitCmds();

	for (unsigned int i = 0; i < this->cmds.size(); i++) {
		this->cmd = this->cmds[i];
		this->splitCmd();

		if (this->serverCommands.find(this->cmd.substr(0, this->cmd.find(' '))) != this->serverCommands.end()) {
			(this->*serverCommands[this->cmd.substr(0, this->cmd.find(' '))])();
		} else {
			std::cout << "comando nao encontrado: " << this->cmd << std::endl;
			// this->resClient("testeeeeeeeeeeeeee");
		}
	}
}

/// @brief RESPONDE UM CLIENTE DE FORMA SIMPLES
void Server::resClient(std::string res) {
	res += "\r\n";
	send(this->client->getFd(), res.c_str(), res.size(), 0);
}