#include <iostream>
#include <sys/socket.h>

// int socket(int domain, int type, int protocol);

int main(void) {
	int server = socket(AF_INET, SOCK_STREAM, 0);

	if (server == -1) {
		std::cerr << "Erro ao criar o socket" << std::endl;
		return (-1);
	}
	return (0);
}