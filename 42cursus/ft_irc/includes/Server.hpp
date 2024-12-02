#ifndef	SERVER_HPP
#define SERVER_HPP

class Server {
	public:
		Server(int server_socket, char *password);
		~Server(void);

		struct pollfd server_fd;
		std::string password;
};

#endif