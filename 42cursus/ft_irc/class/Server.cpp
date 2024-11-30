#include "header.h"

Server::Server(int server_socket) {
	// struct pollfd server_fd;
	this->server_fd.fd = server_socket;
	this->server_fd.events = POLLIN;
}

Server::~Server(void) {

}