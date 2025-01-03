#include "header.h"

bool shutdownServer = false;

int main(int argc, char **argv) {
// std::cout.setf(std::ios::unitbuf); // COM ISSO EU CONSIGO PRINTAR ALGO SEM DEPENDER DE \n
	::validation(argc, argv);
	std::signal(SIGINT, ctrlC);

	restartServer:
	Server *server = new Server(std::atoi(argv[1]), argv[2]);
	if (shutdownServer == false) {
		server->listener();
	}
	delete server;
	if (shutdownServer == false) {
		std::cout << "reiniciando servidor..." << std::endl << std::endl;
		goto restartServer;
	}
	return (0);
}