#ifndef	SERVER_HPP
#define SERVER_HPP

class Client;
class Channel;

class Server {
	public:
		Server(char *port, char *password);
		~Server(void);

		// ./class/Server/Server.cpp
		void newClient(void);
		void deleteClient(void);
		void listener(void);
		void newBuffer(void);

		// ./class/Server/Server.cpp // POR ENQUANTO AKI (FUTURAMENTE DEVO CRIAR UM ARQUIVO SO PARA RESPOSTAS DE CLIENTES/CANAIS MENSAGENS PRIVADAS E ETC)
		void resClient(std::string res);
		void sendClient(std::string res, Client *receiver);
		void resChannel(std::string res, Channel *channel);
		void sendChannel(std::string res, Channel *channel);

		// ./class/Server/getServer.cpp
		int getFd(void) const;
		std::string getIp(void) const;
		std::string getDate(void) const;
		std::string getTime(void) const;

		// ./class/Server/setServer.cpp
		void setPassword(char *password);
		void setPfd(void);
		void setPort(char *port);
		void setServer(char *port);
		void setFds(void);
		void setCmds(void);
		void setTime(void);

		// ./class/Server/cmdsServer.cpp
		void asciiArt(void);
		void CAP(void);
		void luana(void);
		void NICK(void);
		void PASS(void);
		void PING(void);
		void PRIVMSG(void);
		void QUIT(void);
		void USER(void);

		void JOIN(void);
		void MODE(void);
		void TOPIC(void);

		// ./class/Server/utils/nick.cpp
		bool nickInUse(std::string &nick);

		// ./class/Server/utils/join.cpp
		void creatChannel(std::string &channel);
		void joinChannel(std::string &channel);

		// ./class/Server/utils/mode.cpp
		void t(std::string &channel, bool mode);
		void k(std::string &channel, bool mode, std::string password);
		void o(std::string &channel, bool mode, std::string nick);
		void l(std::string &channel, bool mode, std::string limit);

		// ./class/Server/utils/utils.cpp
		bool invalidLine(void);
		std::vector<std::string> split(std::string &str, char delimiter);
		void splitCmds(void);
		void splitCmd(void);
		bool nickChannelInvalid(std::string &nickChannel, std::string charInvalid);
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

		// INFORMACOES DOS CANAIS
		std::map<std::string, Channel *> channels;

		// INFORMACOES DA ATUAL TRANSMISSAO
		Client *client;
		char buffer[512];
		std::vector<std::string> cmds;
		std::string cmd;
		std::vector<std::string> argsCmd;
};

#endif