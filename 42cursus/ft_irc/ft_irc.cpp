#include "header.h"

int server_socket;

/// @brief INICIALIZA O SERVIDOR NA PORTA PASSADA PELO ARGUMENTO
/// @param port PORTA EM Q O SERVIDOR ESTA ABERTO
void init_server(int port, char *password) {
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket == -1) {
		std::cerr << "Erro ao criar o socket" << std::endl;
		exit(1);
	}

	int opt = 1;
	if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
		std::cerr << "Erro ao definir opção de socket" << std::endl;
		exit(1);
	}

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(port);
	if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
		std::cerr << "Erro ao associar o socket ao endereço e porta" << std::endl;
		exit(1);
	}

	if (listen(server_socket, 5)) {
		std::cerr << "Erro ao colocar o socket em modo de escuta" << std::endl;
		close(server_socket);
		exit(1);
	}

	fcntl(server_socket, F_SETFL, O_NONBLOCK);

	std::cout << "Servidor iniciado na porta: " << port << std::endl << "Senha: " << password << std::endl;
}

/// @brief ESCUTA QUALQUER MENSAGEM ENVIADA PELO CLIENTE
/// @param client_socket FD DE CONEXAO DO CLIENTE
/// @param port PORTA EM Q O CLIENTE ESTA SE CONECTANDO (SO PRA TESTE MESMO)
void handle_client(int client_socket, int port) {
	char buffer[100];
	while (true) {
		memset(buffer, 0, 100);
		ssize_t bytes_received = recv(client_socket, buffer, 99, 0);
		if (bytes_received < 0) {
			std::cerr << "Erro ao receber dados" << std::endl;
			break;
		}
		if (bytes_received == 0) {
			std::cout << "Conexao encerrada pelo cliente" << std::endl;
			break;
		}

		std::cout << "Mensagem recebida da porta " << port << ": " << buffer;
	}
	close(client_socket);
}

int main(int argc, char **argv) {
// std::cout << "O PID do processo atual é: " << getpid() << std::endl;
	validation(argc, argv);
	init_server(std::atoi(argv[1]), argv[2]);
	std::signal(SIGINT, ctrlC);

	struct pollfd server_fd;
	server_fd.fd = server_socket;
	server_fd.events = POLLIN;
	std::vector<pollfd> fds;
	fds.push_back(server_fd);
	std::vector<Client> clients;
	char buffer[100];
	while (true) {
		int ret = poll(fds.data(), fds.size(), -1);

		if (ret == -1) {
			std::cout << "erro no poll" << std::endl;
			exit(1);
		} else if (fds[0].revents & POLLIN) {
			new_client(fds, clients);
		} else {
			for (unsigned int i = 1; i < fds.size(); i++) {
				if (fds[i].revents & POLLIN) {
					memset(buffer, 0, 100);
					ssize_t bytes_received = recv(fds[i].fd, buffer, 99, 0);
					if (bytes_received == 0) {
						std::cout << "Conexao encerrada pelo cliente" << std::endl;
						fds.erase(fds.begin() + i);
						clients[i - 1].~client();
						break;
					} else if (bytes_received < 0) {
						std::cerr << "Erro ao receber mensagem" << std::endl;
						break;
					}
					std::cout << "mensagem lida: " << buffer;
					send(fds[i].fd, "ok\n", 3, 0);
				}
			}
		}



	}

		// if (authPassword(client.socket, argv[2]) != -1) {
		// 	handle_client(client.socket, ntohs(client.client.sin_port));
		// }

	// AKI EU DEVERIA FECHAR O SERVIDOR MAS NESSE CASO O LOOP E INFINITO
	return (0);
}