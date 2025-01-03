#ifndef	CLIENT_HPP
#define CLIENT_HPP

class Server;

class Client {
	public:
		Client(Server &server);
		~Client(void);

		// ./class/Client/Client.cpp
		int getFd(void) const;
		std::string getIp(void) const;
		unsigned short getPort(void) const;

		struct sockaddr_in client;
		struct pollfd pfd;
		bool authPass;
		bool authNick;
		bool authUser;
		bool auth;
		std::string nick;
		std::string user;
};

#endif