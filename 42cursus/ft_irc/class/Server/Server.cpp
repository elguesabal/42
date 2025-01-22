#include "header.h"

/// @brief CONSTRUTOR Q INICIALIZA O SERVIDOR
/// @param port PORTA EM Q O SERVIDOR ESTARA ABERTO
/// @param password SENHA Q O SERVIDOR ADOTARA
Server::Server(char *port, char *password) {
	try {
		this->setPassword(password);
		this->setPfd();
		this->setPort(port);
		this->setServer(port);
		this->setFds();
		this->setCmds();
		this->setTime();
		std::cout << "Servidor iniciado na porta " << port << " as " << this->getTime() << " do dia " << this->getDate() << std::endl << "Senha: " << password << std::endl << std::endl;
	} catch (const std::exception &error) {
		shutdownServer = true;
		if (this->getFd() != -1) {
			close(this->getFd());
		}
		throw ;
	}
}

/// @brief DESTRUTOR DA CLASSE Q LIBERA A MEMORIA ALOCADA DINAMICAMENTE DE TODOS OS CLIENTES
Server::~Server(void) {
	while (!this->clients.empty()) {
		this->client = this->clients.front();
		this->deleteClient();
	}

	if (this->getFd() != -1) {
		close(this->getFd());
	}
}

/// @brief CRIA UM NOVO CLIENTE E SALVA O FD NO VECTOR DE FDS E O CLIENTE NO VECTOR DE CLIENTES
void Server::newClient(void) {
	try {
		Client *newClient = new Client(*this);

		this->fds.push_back(newClient->pfd);
		this->clients.push_back(newClient);
	} catch (const std::exception &error) {
		std::cout << "\033[33mWarning:\033[0m " << error.what() << std::endl;
	}
}

/// @brief REMOVE UM CLIENTE DO FD NO VECTOR DE FDS E O CLIENTE NO VECTOR DE CLIENTES ALEM DE FECHAR O FD DO CLIENTE
void Server::deleteClient(void) {
	unsigned int i = std::find(this->clients.begin(), this->clients.end(), client) - this->clients.begin() + 1;

	this->fds.erase(this->fds.begin() + i);
	this->nickClient.erase(this->client->nick);
	this->cmds.clear();
	delete this->client;
	this->clients.erase(this->clients.begin() + i - 1);
}

/// @brief METODO Q COMECA A MONITORAR TODOS OS FDS USANDO poll() E GERENCIA QUAL O DESTINO DO DADO RECEBIDO (SE E UM NOVO CLIENTE, UM CLIENTE DESCONECTANDO)
void Server::listener(void) {
	newComand:
	int ret = poll(this->fds.data(), this->fds.size(), -1);

	if (ret == -1) {
		if (shutdownServer == false) {
			throw std::runtime_error("Erro no poll");
		}
		throw std::runtime_error("SIGINT recebido");
	}

	if (this->fds[0].revents & POLLIN) {
		this->newClient();
		goto newComand;
	}

	for (unsigned int i = 1; i < this->fds.size(); i++) {
		if (this->fds[i].revents & POLLIN) {
			this->client = this->clients[i - 1];
			memset(this->buffer, 0, 512);
			ssize_t bytes_received = recv(this->fds[i].fd, this->buffer, 512, 0);
			if (bytes_received > 0) {
				this->newBuffer();
			} else if (bytes_received == 0) {
				this->deleteClient();
			} else if (bytes_received < 0) {
				std::cout << "\033[33mWarning:\033[0m Erro ao receber mensagem" << std::endl;
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
			std::cout << "\033[33mWarning:\033[0m comando nao encontrado -> '" << this->cmd << "'" << std::endl;
			this->resClient(":" + this->getIp() + " " + ERR_UNKNOWNCOMMAND + " " + this->client->nick + " " + this->argsCmd[0] + " :Comando desconhecido");
		}
	}
}




/// @brief RESPONDE UM CLIENTE DE FORMA SIMPLES
/// @param res RESPOSTA JA PRONTO PARA SER ENVIADA PARA O CLIENTE
void Server::resClient(std::string res) {
	res += "\r\n";
	send(this->client->getFd(), res.c_str(), res.size(), 0);
}

/// @brief MANDA UMA MENSAGEM PARA OUTRO CLIENTE
/// @param res MENSAGEM JA PRONTA PARA SER ENVIADA PARA O CLIENTE
/// @param receiver INFORMACOES DO CLIENTE Q VAI RECEBER A MENSAGEM
void Server::sendClient(std::string res, Client *receiver) {
	res += "\r\n";
	send(receiver->getFd(), res.c_str(), res.size(), 0);
}

/// @brief MANDA UMA MENSAGEM PARA UM CANAL
/// @param res MENSAGEM JA PRONTA PARA SER ENVIADA PARA O CANAL
void Server::resChannel(std::string res, Channel *channel) {
	res += "\r\n";
	for (unsigned int i = 0; i < channel->clients.size(); i++) {
		this->sendClient(res, channel->clients[i]->client);
	}
}

/// @brief MANDA UMA MENSAGEM PARA UM CANAL (EXCETO PARA SI MESMO)
/// @param res MENSAGEM JA PRONTA PARA SER ENVIADA PARA O CANAL
void Server::sendChannel(std::string res, Channel *channel) {
	res += "\r\n";
	for (unsigned int i = 0; i < channel->clients.size(); i++) {
		if (this->client != channel->clients[i]->client) {
			this->sendClient(res, channel->clients[i]->client);
		}
	}
}