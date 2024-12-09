#ifndef	CLIENT_HPP
#define CLIENT_HPP

class Server;

class Client {
	public:
		Client(Server &server);
		~Client(void);

		// bool operator == (const Client &client) const; // EU SO PRECISAVA DE IMPLEMENTAR == QUANDO EU DEFINIA std::vector<Client> clients;

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