#include "header.h"

// int server_socket; // DESATIVANDO PARA TENTAR NAO USAR VARIAVEL GLOBAL

int main(int argc, char **argv) {
	validation(argc, argv);

	Server server(std::atoi(argv[1]), argv[2]);

	std::signal(SIGINT, ctrlC); // AKI AINDA NAO SEI COMO TRATAR

	server.listener();

	return (0);
}