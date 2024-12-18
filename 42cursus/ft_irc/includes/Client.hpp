#ifndef	CLIENT_HPP
#define CLIENT_HPP

class Server;

class Client {
	public:
		Client(Server &server);
		~Client(void);

		unsigned short getFd(void) const;
		std::string getIp(void) const;
		unsigned short getPort(void) const;

		struct sockaddr_in client;
		struct pollfd pfd;
		bool auth;
		std::string nick;
		// std::string user;
};

#endif