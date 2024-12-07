#ifndef	CLIENT_HPP
#define CLIENT_HPP

// #include "header.h"
// #include "Server.hpp"

class Server;

// CLASSE CRIADA PARA ARMAZENAR DADOS DO CLIENTE CONECTADO
class Client {
	public:
		Client(Server &server);
		~Client(void);

		bool operator == (const Client &client) const;

		// void closeClient(void); // COMECEI A USAR UM ARRAI DE PONTEIROS DE CLIENTES E AGR DESATIVEI ISSO
		std::string ip(void) const;
		unsigned short port(void) const;

		struct sockaddr_in client;
		struct pollfd pfd;
		bool auth;
		short int password_attempts;
		// std::string nickname;
		// std::string name;
		// std::string channel;
		// int adm = 0;
};

#endif