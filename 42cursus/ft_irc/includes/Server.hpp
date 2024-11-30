#ifndef	SERVER_HPP
#define SERVER_HPP

class Server {
	public:
		Server(int server_socket);
		~Server(void);

		struct pollfd server_fd;
};

#endif