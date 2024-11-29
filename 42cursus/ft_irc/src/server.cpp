#include "header.h"

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