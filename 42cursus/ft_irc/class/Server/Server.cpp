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
	this->addCommands();
	std::cout << "Servidor iniciado na porta: " << port << std::endl << "Senha: " << password << std::endl << std::endl;
}

/// @brief DESTRUTOR DA CLASSE
Server::~Server(void) {
	// close(this->pfd.fd); SE EU USO CTRL+C ESSA BAGACA NAO E CHAMADA
}

void Server::addCommands(void) {
	this->commands["CAP"] = &Server::CAP; // O CLIENTE MANDA UM "CAP END" ALEM DE "CAP LS 302"
	this->commands["PASS"] = &Server::PASS;
	this->commands["NICK"] = &Server::NICK;
	this->commands["USER"] = &Server::USER;
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

/// @brief METODO Q ENCAMINHA COMO O BUFFER RECEBIDO POR UM CLIENTE ESPECIFICO VAI SER TRATADO
void Server::newBuffer(void) {
	this->bufferStr = this->bufferChar;
	this->splitMessage();

	for (unsigned int i = 0; i < this->bufferStrs.size(); i++) {
		this->bufferStr = this->bufferStrs[i]; // AKI EU TO SEMPRE ATUALIZANDO this->bufferStr PARA NAO PRECISAR FICAR PASSANDO COMO PARAMETRO PQ NAO FAZER COM INDECE E CLIENTE?

		// if (this->bufferStr == "CAP LS 302") { // O CLIENTE MANDA UM "CAP END" ENTAO AINDA NAO VOU PROCURAR APENAS POR CAP
		// 	this->CAP();
		// } else if (this->bufferStr.find("PASS") == 0) {
		// 	this->PASS(); // BELEZA EU MANDO UMA MENSAGEM DE SENHA ERRADA E EXCLUO O CLIENTE E FECHO O FD POREM AINDA EXECUTO OS COMANDOS NICK E USER Q VEM JUNTO
		// } else if (this->bufferStr.find("NICK") == 0) {
		// 	this->NICK();
		// } else if (this->bufferStr.find("USER") == 0) {
		// 	this->USER();
		// } else {
		// 	// send(client->getFd(), "/JOIN aaa\r\n", 11, 0);
		// 	// std::cout << "caiu no else" << std::endl;
		// 	// std::cout << "caiu no else: " << this->bufferStr << " i: " << i << std::endl;
		// }

		// TO QUERENDO TIRAR ESSE EMARANHADO DE IF E ELSE POR UM std::map
		if (this->commands.find(this->bufferStr.substr(0, this->bufferStr.find(' '))) != this->commands.end()) {
			(this->*commands[this->bufferStr.substr(0, this->bufferStr.find(' '))])();
		} else {
			std::cout << "comando nao encontrado: " << this->bufferStr << std::endl;
		}
	}
}