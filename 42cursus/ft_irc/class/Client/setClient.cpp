#include "header.h"

/// @brief SALVA INFORMACOES NO pfd
void Client::setPfd(Server &server) {
	socklen_t client_address_len = sizeof(this->client);

	this->pfd.fd = accept(server.getFd(), (struct sockaddr *)&this->client, &client_address_len);
	if (this->getFd() == -1) {
		throw std::runtime_error("Erro ao aceitar conexão");
	}
	this->pfd.events = POLLIN;
}

/// @brief ATUALIZA O NICK EM TODOS OS CANAIS E NA PROPRIA CLASSE
void Client::setNick(std::string &nick) {
	for (unsigned int i = 0; i < this->channels.size(); i++) {
		this->channels[i]->nickClient[nick] = this->channels[i]->nickClient[this->nick];
		this->channels[i]->nickClient.erase(this->nick);

		// this->channels[i]->operators; // PQ RAIOS EU TENHO ESSA VARIAVEL SE EU APENAS INICIALISO ELA??????
	}
	this->nick = nick;
}