#include "header.h"

/// @brief FUNCAO RESPONSAVEL POR MANIPULAR SINAIS
void handler(int signal) {
	if (signal == SIGINT) {
		std::cout << std::endl << "Fechando servidor..." << std::endl;
		shutdownServer = true;
	}
}