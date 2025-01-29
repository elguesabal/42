#ifndef	CLIENT_HPP
#define CLIENT_HPP

class Server;

class Client {
	public:
		Client(Server &server);
		~Client(void);

		// ./class/Client/getClient.cpp
		int getFd(void) const;
		std::string getIp(void) const;
		unsigned short getPort(void) const;

		// ./class/Client/setClient.cpp
		void setPfd(Server &server);

		struct sockaddr_in client;
		struct pollfd pfd;
		bool authPass;
		bool authNick;
		bool authUser;
		bool auth;
		std::string nick;
		std::string user;

		// std::vector<Channel *> channels; // VOU CRIAR UM vector DENTRO DO CLIENTE Q VAI GUARDAR TODOS OS CANAIS
};

#endif