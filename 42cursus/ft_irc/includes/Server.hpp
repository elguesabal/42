#ifndef	SERVER_HPP
#define SERVER_HPP

// #include "Client.hpp"

class Client;

// CLASSE CRIADA PARA ARMAZENAR DADOS DO SERVIDOR
class Server {
	public:
		Server(int port, char *password);
		~Server(void);

		void listener(void);
		void newClient(void);
		void deleteClient(Client *client);
		void newBuffer(Client *client);
		void authentication(Client *client);

		struct sockaddr_in server;
		struct pollfd pfd;
		std::vector<pollfd> fds;
		std::vector<Client *> clients;
		std::string password;
		char bufferChar[1024];
		std::string bufferStr;
};

#endif