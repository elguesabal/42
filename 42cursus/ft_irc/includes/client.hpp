#ifndef	CLIENT_HPP
#define CLIENT_HPP

#include "header.h"

// CLASSE CRIADA PARA ARMAZENAR DADOS DO CLIENTE CONECTADO
class Client {
	public:
		Client(void);
		Client(int socket, sockaddr_in _client);
		~Client(void);

		std::string ip(void) const;
		unsigned short port(void) const;

		const int socket;
		struct sockaddr_in client;
		// int password = 0;
		// std::string nickname;
		// int adm = 0;

	private:

};

#endif