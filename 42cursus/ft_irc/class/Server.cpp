#include "header.h"

/// @brief CONSTRUTOR Q INICIALIZA O SERVIDOR
/// @param port PORTA EM Q O SERVIDOR ESTARA ABERTO
/// @param password SENHA Q O SERVIDOR ADOTARA
Server::Server(int port, char *password) {
	this->pfd.fd = socket(AF_INET, SOCK_STREAM, 0);
	// server_socket = this->pfd.fd;
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
			// new_client(server);
			this->newClient();
		} else {
			for (unsigned int i = 1; i < this->fds.size(); i++) {
				if (this->fds[i].revents & POLLIN) {
					memset(this->bufferChar, 0, 1024);
					ssize_t bytes_received = recv(this->fds[i].fd, this->bufferChar, 99, 0);
					this->bufferStr = this->bufferChar;
					if (bytes_received > 0) {
						// new_buffer(*this, this->clients[i - 1]);
						this->newBuffer(this->clients[i - 1]);
					} else if (bytes_received == 0) {
						// delete_client(server, server.clients[i - 1]);
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
    // Client newClient(*this);
	// this->fds.push_back(newClient.pfd);
	// this->clients.push_back(newClient);

    Client *newClient = new Client(*this);
	this->fds.push_back(newClient->pfd);
	this->clients.push_back(newClient);
}

/// @brief REMOVE UM CLIENTE DO FD NO VECTOR DE FDS E O CLIENTE NO VECTOR DE CLIENTES
void Server::deleteClient(Client *client) {
	unsigned int i = std::find(this->clients.begin(), this->clients.end(), client) - this->clients.begin() + 1;

	// std::cout << "Conexao encerrada do ip " << inet_ntoa(this->clients[i - 1]->client.sin_addr) << " na porta " << ntohs(this->clients[i - 1]->client.sin_port) << std::endl; // AGR ISSO ESTA SENDO FEITO NO DESTRUTOR DO CLIENTE
	this->fds.erase(this->fds.begin() + i);
	// this->clients[i - 1]->closeClient(); // std::vector<Client *> clients; VIROU ARRAY DE PONTEIROS
	delete this->clients[i - 1];
	this->clients.erase(this->clients.begin() + i - 1);
}

/// @brief FUNCAO Q ENCAMINHA COMO O BUFFER RECEBIDO POR UM CLIENTE ESPECIFICO VAI SER TRATADO
/// @param client REFERENCIA Q CONTEM AS INFORMACOES DO CLIENTE
void Server::newBuffer(Client *client) {
	if (client->auth == false) {
		// authentication(*this, client);
		this->authentication(client);
	} else {
		for (unsigned int i = 1; i < this->fds.size(); i++) {
			if (this->fds[i].fd != client->pfd.fd) {
				send(this->fds[i].fd, this->bufferStr.c_str(), this->bufferStr.size(), 0);
			}
		}
	}

	// else if (client.nickname) {
	// 	// PROXIMO PASSO
	// 	// TALVEZ A PROXIMA COISA Q EU FACA SEJA MUDAR A MEMORIA PARA DINAMICA PARA OS CLIENTES
	// } 
}

/// @brief FUNCAO Q LIDA COM INSERCAO DE SENHA QUANDO O CLIENTE SE CONECTA
/// @param client REFERENCIA Q CONTEM AS INFORMACOES DO CLIENTE
void Server::authentication(Client *client) {
	this->bufferStr.erase(this->bufferStr.size() - 1);
	if (this->bufferStr == this->password) {
		client->auth = true;
		send(client->pfd.fd, "Bem vindo ao servidor!\n", 23, 0);
	} else {
		if (client->password_attempts > 1) {
			send(client->pfd.fd, "Limite de tentativas excedidas. Aguarde e tente novamente mais tarde\n", 69, 0);
			// delete_client(server, client);
			this->deleteClient(client);
		} else {
			send(client->pfd.fd, "Senha incorreta! Digite novamente: ", 35, 0);
			client->password_attempts++;
		}
	}
}