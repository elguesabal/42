#include "header.h"

// int server_socket; // DESATIVANDO PARA TENTAR NAO USAR VARIAVEL GLOBAL

int main(int argc, char **argv) {
	validation(argc, argv);
	// init_server(std::atoi(argv[1]), argv[2]);
	Server server(std::atoi(argv[1]), argv[2]);

	std::signal(SIGINT, ctrlC); // AKI AINDA NAO SEI COMO TRATAR

	// listener(Server(server_socket, argv[2]));
	listener(server);

	// AKI EU DEVERIA FECHAR O SERVIDOR MAS NESSE CASO O LOOP E INFINITO
	return (0);
}