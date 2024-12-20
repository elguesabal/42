#ifndef	SERVER_HPP
#define SERVER_HPP

class Client;

class Server {
	public:
		Server(int port, char *password);
		~Server(void);

		void addCommands(void);
		void newClient(void);
		void deleteClient(void);
		void listener(void);
		void newBuffer(void);

		std::string getIp(void) const;

		void CAP(void);
		void PASS(void);
		void NICK(void);
		void USER(void);

		bool nickInvalid(std::string &nick);
		bool nickInUse(std::string &nick);

		void splitMessage(void);
		std::string toUpper(std::string &str);

		struct sockaddr_in server;
		struct pollfd pfd;
		std::string password;
		std::map<std::string, void (Server::*)()> commands;

		std::vector<pollfd> fds;
		std::vector<Client *> clients;
		std::map<std::string, Client *> nickClient;

		Client *client;
		unsigned short index;
		char bufferChar[1024];
		std::string bufferStr;
		std::vector<std::string> bufferStrs;
};

#endif