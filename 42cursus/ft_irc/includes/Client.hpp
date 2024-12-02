#ifndef	CLIENT_HPP
#define CLIENT_HPP

#include "header.h"

// CLASSE CRIADA PARA ARMAZENAR DADOS DO CLIENTE CONECTADO
class Client {
	public:
		Client(int server_socket);
		// Client(int socket, sockaddr_in _client, pollfd pfd);
		~Client(void);

		bool operator == (const Client &client) const;

		void close_client(void);
		std::string ip(void) const;
		unsigned short port(void) const;

		struct sockaddr_in client;
		struct pollfd pfd;
		// unsigned int i; AKI EU COLOCARIA O INDICE DO CLIENTE DENTRO DO VECTOR MAS COMO EU ATUALIZO???
		bool auth;
		short int password_attempts;
		// std::string nickname;
		// std::string name;
		// int adm = 0;

	private:

};

#endif