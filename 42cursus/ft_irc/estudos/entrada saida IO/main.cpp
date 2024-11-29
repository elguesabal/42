#include <poll.h>
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <unistd.h> // USANDO ISSO PARA VER O PID
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// ssize_t recv(int sockfd, void *buf, size_t len, int flags);
// int main(void) {
// 	int server = socket(AF_INET, SOCK_STREAM, 0);
// 	if (server == -1) {
// 		std::cout << "Erro ao criar o socket" << std::endl;
// 		return (-1);
// 	}
// 	struct sockaddr_in server_address;
// 	server_address.sin_family = AF_INET;
// 	server_address.sin_addr.s_addr = INADDR_ANY;
// 	server_address.sin_port = htons(8000);
// 	if (bind(server, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
// 		std::cout << "Erro ao associar o socket ao endereço e porta" << std::endl;
// 		return (-1);
// 	}
// 	if (listen(server, 5) == -1) {
// 		std::cout << "Erro ao colocar o socket em modo de escuta" << std::endl;
// 		close(server);
// 		return (-1);
// 	}
// 	std::cout << "Servidor em escuta na porta 8000..." << std::endl;

// 	struct sockaddr_in client;
// 	socklen_t client_address_len = sizeof(client);
// 	int client_socket = accept(server, (struct sockaddr *)&client, &client_address_len);
// 	if (client_socket == -1) {
// 		std::cout << "Erro ao aceitar conexão" << std::endl;
// 		close(server);
// 		return (-1);
// 	}
// 	std::cout << "Conexão aceita do cliente: " << inet_ntoa(client.sin_addr) << " na porta " << ntohs(client.sin_port) << std::endl;

// 	char buffer[100];
// 	while (true) {
// 		memset(buffer, 0, 100);

// 		// std::cout << "esperando mensagem..." << std::endl;
// 		ssize_t bytes_received = recv(client_socket, buffer, 99, MSG_DONTWAIT); // MSG_DONTWAIT
// 		if (bytes_received > 0) {
// 			buffer[bytes_received] = '\0';
// 			std::cout << "Mensagem recebida: " << buffer;
// 		} else if (bytes_received == 0) {
// 			std::cout << "Cliente desconectado" << std::endl;
// 			break;
// 		} else {
// 			std::cout << "Erro ao receber dados" << std::endl;
// 			break;
// 		}

// 		sleep(5);
// 	}

// 	close(client_socket);
// 	return (0);
// }


// int poll(struct pollfd *fds, nfds_t nfds, int timeout);
int main(void) {
	int fd = open("arquivo.txt", O_RDONLY);

	if (fd < 0) {
		perror("Erro ao abrir o arquivo");
		return (1);
	}

	struct pollfd pfd;
	pfd.fd = fd;
	pfd.events = POLLIN;

	std::cout << "Aguardando dados no arquivo..." << std::endl;

	int ret = poll(&pfd, 1, -1);
	if (ret > 0 && (pfd.revents & POLLIN)) {
		std::cout << "Dados disponíveis para leitura no arquivo" << std::endl;
	} else {
		std::cout << "Erro no poll" << std::endl;
	}

	close(fd);
	return (0);
}



// int main(void) {
// std::cout << "O PID do processo atual é: " << getpid() << std::endl;
// 	struct pollfd pfd;

// 	pfd.fd = STDIN_FILENO;
// 	pfd.events = POLLIN;

// 	std::cout << "Aguardando dados..." << std::endl;

// 	int ret = poll(&pfd, 1, -1);
// 	if (ret > 0 && (pfd.revents & POLLIN)) {
// 		std::cout << "Dados disponíveis para leitura" << std::endl;
// 	} else {
// 		std::cout << "Erro no poll" << std::endl;
// 	}

// 	return (0);
// }



// int main(void) {
// 	struct pollfd fds[2];

// 	fds[0].fd = STDIN_FILENO;
// 	fds[0].events = POLLIN;

// 	fds[1].fd = STDOUT_FILENO;
// 	fds[1].events = POLLIN;

// 	std::cout << "Esperando eventos..." << std::endl;
// 	int ret = poll(fds, 2, 5000);

// 	if (ret == -1) {
// 		std::cout << "erro no poll" << std::endl;
// 		return (1);
// 	} else if (ret == 0) {
// 		std::cout << "Tempo esgotado sem eventos" << std::endl;
// 	} else {
// 		if (fds[0].revents & POLLIN) {
// 			std::cout << "Dados disponíveis no stdin" << std::endl;
// 		}

// 		if (fds[1].revents & POLLIN) {
// 			std::cout << "Dados disponíveis no fd 4" << std::endl;
// 		}
// 	}

// 	return (0);
// }