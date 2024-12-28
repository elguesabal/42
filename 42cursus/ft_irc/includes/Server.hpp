#ifndef	SERVER_HPP
#define SERVER_HPP

class Client;

class Server {
	public:
		Server(int port, char *password);
		~Server(void);

		// ./class/Server/Server.cpp
		void addCmds(void);
		void newClient(void);
		void deleteClient(void);
		void listener(void);
		void newBuffer(void);

		// ./class/Server/Server.cpp // POR ENQUANTO AKI (FUTURAMENTE DEVO CRIAR UM ARQUIVO SO PARA RESPOSTAS DE CLIENTES CANAIS MENSAGENS PRIVADAS E ETC)
		void resClient(std::string res);

		// ./class/Server/getServer.cpp
		int getFd(void) const;
		std::string getIp(void) const;
		std::string getDate(void) const;
		std::string getTime(void) const;

		// ./class/Server/cmdsServer.cpp
		void CAP(void);
		void PASS(void);
		void NICK(void);
		void USER(void);
		void QUIT(void);

		// ./class/Server/utils/nick.cpp
		bool nickInvalid(std::string &nick);
		bool nickInUse(std::string &nick);

		// ./class/Server/utils/utils.cpp
		bool invalidLine(void);
		void splitCmds(void);
		void splitCmd(void);
		std::string toUpper(std::string &str);
		void authentication(void);

		// INFORMACOES DO SERVIDOR
		struct sockaddr_in server;
		struct pollfd pfd;
		std::string password;
		std::map<std::string, void (Server::*)()> serverCommands;
		std::tm *time;

		// INFORMACOES DOS CLIENTES
		std::vector<pollfd> fds;
		std::vector<Client *> clients;
		std::map<std::string, Client *> nickClient;

		// INFORMACOES DA ATUAL TRANSMISSAO
		Client *client;
		char buffer[512];
		std::vector<std::string> cmds;
		std::string cmd;
		std::vector<std::string> argsCmd;
};

#endif