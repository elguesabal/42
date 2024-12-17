#ifndef	SERVER_HPP
#define SERVER_HPP

class Client;

class Server {
	public:
		Server(int port, char *password);
		~Server(void);

		void newClient(void);
		void deleteClient(void);
		void listener(void);
		void newBuffer(void);


		std::string getIp(void) const;

		void CAP(void);
		void PASS(void);
		void NICK(void);

		struct sockaddr_in server;
		struct pollfd pfd;
		std::vector<pollfd> fds;
		std::vector<Client *> clients;
		Client *client;
		unsigned short index;
		std::string password;
		char bufferChar[1024];
		std::string bufferStr;
		std::vector<std::string> bufferStrs;
		std::set<std::string> nicks;
};

#endif