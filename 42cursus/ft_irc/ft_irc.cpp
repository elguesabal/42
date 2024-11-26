#include "header.h"

int server_socket;

/// @brief INICIALIZA O SERVIDOR NA PORTA PASSADA PELO ARGUMENTO
/// @param port PORTA EM Q O SERVIDOR ESTA ABERTO
/// @return RETORNA UM NUMERO POSITIVO 
int server(int port) {
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket == -1) {
		std::cerr << "Erro ao criar o socket" << std::endl;
		return (-1);
	}

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(port);
	if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
		std::cerr << "Erro ao associar o socket ao endereço e porta" << std::endl;
		return (-1);
	}

	if (listen(server_socket, 5)) {
		std::cerr << "Erro ao colocar o socket em modo de escuta" << std::endl;
		close(server_socket);
		return (-1);
	}

	return (server_socket);
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
	if (validation(argc, argv))
		return (0);
	server_socket = server(std::atoi(argv[1]));
std::cout << "teste: " << server_socket << std::endl;
	if (server_socket == -1)
		return (-1);
	std::signal(SIGINT, ctrlC);

	// std::vector<int> client_sockets;
	int new_socket;
	struct sockaddr_in client_address;
	socklen_t client_address_len = sizeof(client_address);
	std::cout << "Servidor iniciado na porta: " << argv[1] << std::endl << "Senha: " << argv[2] << std::endl;
	while (true) {
		new_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
		if (new_socket == -1) {
			std::cerr << "Erro ao aceitar conexão" << std::endl;
			close(server_socket);
			return (-1);
		}

		// client_sockets.push_back(new_socket);
		// std::cout << "Conexão aceita do cliente: " << inet_ntoa(client_address.sin_addr) << " na porta " << ntohs(client_address.sin_port) << std::endl;
		// std::cout << "a" << std::endl;
		// std::cout << "Conexao aceita do ip: " << inet_ntoa(client_address.sin_addr) << " na porta " << ntohs(client_address.sin_port) << std::endl;

		// send(new_socket, "Bem vindo ao servidor!\n Senha: ", 31, 0);
		// send(new_socket, "Senha: ", 7, 0);
		if (authPassword(new_socket, argv[2]) != -1) {
			handle_client(new_socket, ntohs(client_address.sin_port));
		}
	}

	// AKI EU DEVERIA FECHAR O SERVIDOR MAS NESSE CASO O LOOP E INFINITO
	return (0);
}