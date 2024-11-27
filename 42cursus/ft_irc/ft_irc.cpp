#include "header.h"

int server_socket;

/// @brief INICIALIZA O SERVIDOR NA PORTA PASSADA PELO ARGUMENTO
/// @param port PORTA EM Q O SERVIDOR ESTA ABERTO
void server(int port, char *password) {
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket == -1) {
		std::cerr << "Erro ao criar o socket" << std::endl;
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

	std::cout << "Servidor iniciado na porta: " << port << std::endl << "Senha: " << password << std::endl;
	// return (server_socket);
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
	server(std::atoi(argv[1]), argv[2]);

	std::signal(SIGINT, ctrlC);

	std::vector<Client> clients;
	// int new_socket;
	// struct sockaddr_in client_address;
	// socklen_t client_address_len = sizeof(client_address);
	while (true) {
		// new_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
		// if (new_socket == -1) {
		// 	std::cerr << "Erro ao aceitar conexão" << std::endl;
		// 	close(server_socket);
		// 	return (-1);
		// } else {
		// 	std::cout << "conexao aceita" << std::endl;
		// }

		// clients.push_back(new_socket);


		// Client new_client = Client(new_socket, client_address);
		// clients.push_back(new_client);

		Client client = new_client();
		clients.push_back(client);
	
		// std::cout << "Conexão aceita do cliente: " << inet_ntoa(client_address.sin_addr) << " na porta " << ntohs(client_address.sin_port) << std::endl;
		// std::cout << "a" << std::endl;
		// std::cout << "Conexao aceita do ip: " << inet_ntoa(client_address.sin_addr) << " na porta " << ntohs(client_address.sin_port) << std::endl;

		// send(new_socket, "Bem vindo ao servidor!\n Senha: ", 31, 0);
		// send(new_socket, "Senha: ", 7, 0);
		if (authPassword(client.socket, argv[2]) != -1) {
			handle_client(client.socket, ntohs(client.client.sin_port));
		}
	}

	// AKI EU DEVERIA FECHAR O SERVIDOR MAS NESSE CASO O LOOP E INFINITO
	return (0);
}