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