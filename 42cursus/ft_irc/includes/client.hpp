#ifndef	CLIENT_HPP
#define CLIENT_HPP

#include "header.h"

// CLASSE CRIADA PARA ARMAZENAR DADOS DO CLIENTE CONECTADO
class Client {
	public:
		Client(void);
		// Client(int socket, sockaddr_in _client, pollfd pfd);
		~Client(void);

		std::string ip(void) const;
		unsigned short port(void) const;

		// int socket; // NAO TO USANDO MAIS ISSO PQ TEM pollfd
		struct sockaddr_in client;
		struct pollfd pfd;
		// int password = 0;
		// std::string nickname;
		// int adm = 0;

	private:

};

#endif