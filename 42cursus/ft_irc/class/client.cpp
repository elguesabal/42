#include "header.h"

Client::Client(void) : socket(-1) {

}

Client::Client(int socket, sockaddr_in client) : socket(socket), client(client) {

}

Client::~Client(void) {

}

std::string Client::ip(void) const {
	return ("vampeta");
}

unsigned short Client::port(void) const {
	return (5);
}