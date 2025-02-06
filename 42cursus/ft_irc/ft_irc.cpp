#include "header.h"

bool shutdownServer = false;

int main(int argc, char **argv) {
	if (argc != 3) {
		std::cout << "Numero de argumentos invalido" << std::endl;
		return (0);
	}
	std::signal(SIGINT, handler);
	std::signal(SIGPIPE, handler);

	Server *server;
	restartServer:
	try {
		server = new Server(argv[1], argv[2]);
		server->listener();
	} catch (const std::exception &error) {
		delete server;
		std::cout << "\033[31mError:\033[0m " << error.what() << std::endl;
		if (shutdownServer == false) {
			std::cout << "reiniciando servidor..." << std::endl << std::endl;
			goto restartServer;
		}
	}
	return (0);
}