#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


// int socket(int domain, int type, int protocol);
// int main(void) {
// 	int server = socket(AF_INET, SOCK_STREAM, 0);
// 	if (server == -1) {
// 		std::cerr << "Erro ao criar o socket" << std::endl;
// 		return (-1);
// 	}
// 	return (0);
// }



// int setsockopt(int socket, int level, int option_name, const void *option_value, socklen_t option_len);
// int main(void) {
// 	return (0);
// }



// int bind(int socket, const struct sockaddr *address, socklen_t address_len);
int main(void) {
	int server = socket(AF_INET, SOCK_STREAM, 0);
	if (server == -1) {
		std::cerr << "Erro ao criar o socket" << std::endl;
		return (-1);
	}

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(8080);
	if (bind(server, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
		std::cerr << "Erro ao associar o socket ao endereço e porta" << std::endl;
		return (-1);
	}
	return (0);
}