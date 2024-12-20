#include "header.h"

/// @brief METODO Q BUSCA O FD DO CLIENTE
/// @return RETORNA O FD DO CLIENTE
unsigned short Client::getFd(void) const {
	return (this->pfd.fd);
}

/// @brief METODO Q BUSCA O IP DO CLIENTE
/// @return RETORNA O IP DO CLIENTE
std::string Client::getIp(void) const {
	return (inet_ntoa(this->client.sin_addr));
}

/// @brief METODO Q BUSCA A PORTA DO CLIENTE
/// @return RETORNA A PORTA DO CLIENTE
unsigned short Client::getPort(void) const {
	return (ntohs(this->client.sin_port));
}