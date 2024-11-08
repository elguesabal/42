#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// int listen(int socket, int backlog);
// int main(void) {
// 	int server = socket(AF_INET, SOCK_STREAM, 0);
// 	if (server == -1) {
// 		std::cerr << "Erro ao criar o socket" << std::endl;
// 		return (-1);
// 	}

// 	struct sockaddr_in server_address;
// 	server_address.sin_family = AF_INET;
// 	server_address.sin_addr.s_addr = INADDR_ANY;
// 	server_address.sin_port = htons(8080);
// 	if (bind(server, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
// 		std::cerr << "Erro ao associar o socket ao endereço e porta" << std::endl;
// 		return (-1);
// 	}

// 	if (listen(server, 5) == -1) {
// 		std::cerr << "Erro ao colocar o socket em modo de escuta" << std::endl;
// 		close(server);
// 		return (-1);
// 	}
// 	std::cout << "Servidor em escuta na porta 8080..." << std::endl;
// 	close(server);

// 	return (0);
// }



// int accept(int server_socket, struct sockaddr* client_address, socklen_t* address_len);
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

	if (listen(server, 5) == -1) {
		std::cerr << "Erro ao colocar o socket em modo de escuta" << std::endl;
		close(server);
		return (-1);
	}
	std::cout << "Servidor em escuta na porta 8080..." << std::endl;

	struct sockaddr_in client;
	socklen_t client_address_len = sizeof(client);
	int client_socket = accept(server, (struct sockaddr *)&client, &client_address_len);
	if (client_socket == -1) {
		std::cerr << "Erro ao aceitar conexão" << std::endl;
		close(server);
		return (-1);
	}
	std::cout << "Conexão aceita do cliente: " << inet_ntoa(client.sin_addr) << " na porta " << ntohs(client.sin_port) << std::endl;

	close(client_socket);
	close(server);

	return (0);
}