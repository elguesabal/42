#include "header.h"

/// @brief FUNCAO RESPONSAVEL POR MANIPULAR SINAIS
void ctrlC(int signal) {
	if (signal == SIGINT) {
		std::cout << std::endl << "Fechando servidor..." << std::endl;
		shutdownServer = true;
	}
}




// AKI EU PODERIA FAZER UMA CLASSE SIGNAL COM UMA FUNCAO PARA USO EXTERNO E UMA VARIAVEL DE CONTROLE?
// class Signal {
// 	public:
// 		void signal(int signal);
// 		bool shutdownServer;
// };