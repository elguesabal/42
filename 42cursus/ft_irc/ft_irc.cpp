#include "header.h"

int server_socket;

/// @brief ESCUTA QUALQUER MENSAGEM ENVIADA PELO CLIENTE
/// @param client_socket FD DE CONEXAO DO CLIENTE
/// @param port PORTA EM Q O CLIENTE ESTA SE CONECTANDO (SO PRA TESTE MESMO)
// void handle_client(int client_socket, int port) {
// 	char buffer[100];
// 	while (true) {
// 		memset(buffer, 0, 100);
// 		ssize_t bytes_received = recv(client_socket, buffer, 99, 0);
// 		if (bytes_received < 0) {
// 			std::cerr << "Erro ao receber dados" << std::endl;
// 			break;
// 		}
// 		if (bytes_received == 0) {
// 			std::cout << "Conexao encerrada pelo cliente" << std::endl;
// 			break;
// 		}

// 		std::cout << "Mensagem recebida da porta " << port << ": " << buffer;
// 	}
// 	close(client_socket);
// }

int main(int argc, char **argv) {
// std::cout << "O PID do processo atual é: " << getpid() << std::endl;
	validation(argc, argv);
	init_server(std::atoi(argv[1]), argv[2]);
	std::signal(SIGINT, ctrlC);

	// Server server(server_socket, argv[2]);
	listener(Server(server_socket, argv[2]));

		// if (authPassword(client.socket, argv[2]) != -1) {
		// 	handle_client(client.socket, ntohs(client.client.sin_port));
		// }

	// AKI EU DEVERIA FECHAR O SERVIDOR MAS NESSE CASO O LOOP E INFINITO
	return (0);
}