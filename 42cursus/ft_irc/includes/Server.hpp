#ifndef	SERVER_HPP
#define SERVER_HPP

class Client;

class Server {
	public:
		Server(int port, char *password);
		~Server(void);

		void addCmds(void);
		void newClient(void);
		void deleteClient(void);
		void listener(void);
		void newBuffer(void);

		void resClient(std::string res);

		std::string getIp(void) const;

		void CAP(void);
		void PASS(void);
		void NICK(void);
		void USER(void);

		bool nickInvalid(std::string &nick);
		bool nickInUse(std::string &nick);

		void splitCmds(void);
		void splitCmd(void);
		std::string toUpper(std::string &str);

		struct sockaddr_in server;
		struct pollfd pfd;
		std::string password;
		std::map<std::string, void (Server::*)()> serverCommands;

		std::vector<pollfd> fds;
		std::vector<Client *> clients;
		std::map<std::string, Client *> nickClient;

		Client *client;
		unsigned short index;
		char buffer[512];
		std::vector<std::string> cmds;
		std::string cmd;
		std::vector<std::string> argsCmd;
};

#endif