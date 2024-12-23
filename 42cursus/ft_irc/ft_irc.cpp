#include "header.h"

int main(int argc, char **argv) {
// std::cout.setf(std::ios::unitbuf); // COM ISSO EU CONSIGO PRINTAR ALGO SEM DEPENDER DE \n
	validation(argc, argv);
	Server server(std::atoi(argv[1]), argv[2]);
	std::signal(SIGINT, ctrlC); // AKI AINDA NAO SEI COMO TRATAR
	server.listener();


	// restartServer:
	// 	Server server(std::atoi(argv[1]), argv[2]);
	// 	server.listener();
	// 	std::cout << "reiniciando servidor..." << std::endl;
	// goto restartServer;
	return (0);
}