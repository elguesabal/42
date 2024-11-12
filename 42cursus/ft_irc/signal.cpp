#include "header.h"

// void ctrlC(int signal) {
// 	if (signal == SIGINT) {
// 		std::cout << "teste" << std::endl;

// 	}
// }

void ctrlC(int signal) { // POR ENQUANTO ASSIM
	if (signal == SIGINT) {
		close(server_socket);
		exit(0);
	}
}