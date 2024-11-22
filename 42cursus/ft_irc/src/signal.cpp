#include "header.h"

// void ctrlC(int signal, siginfo_t *info, void *context) {
// (void)signal;
// (void)info;
// (void)context;

// 	// static int server_socket;

// 	// signalData *data = reinterpret_cast<signalData *>(info->si_value.sival_ptr);
// 	// if (info) {
// 	// 	std::cout << "cheio" << std::endl;
// 	// 	// close(data->server_socket);
// 	// 	// server_socket = data->server_socket;
// 	// } else {
// 	// 	std::cout << "vazio" << std::endl;
// 	// }
// 	// std::cout << "teste fora" << std::endl;
// 	// exit(0);
// }

		// COMO CHAMAR A FUNCAO ctrlC() USANDO sigaction (NAO ESTA FUNCIONANDO)
// struct sigaction action = {}; // NAO SEI PQ MAS TA SENDO ENVIADO UM SIGNAL LOGO NO COMECO DO CODIGO
// signalData data = { server_socket };
// action.sa_flags = SA_SIGINFO;
// action.sa_sigaction = ctrlC;

// sigemptyset(&action.sa_mask);
// sigaddset(&action.sa_mask, SIGINT);

// sigaction(SIGINT, &action, NULL);
// sigval sig_value = {};
// sig_value.sival_ptr = &data;
// sigqueue(getpid(), SIGINT, sig_value); // ALIAS SEI SIM MAS MESMO A FUNCAO NAO FAZENDO NADA O SERVIDO DA "Erro ao aceitar conexão"
		// COMO CHAMAR A FUNCAO ctrlC() USANDO sigaction (NAO ESTA FUNCIONANDO)



void ctrlC(int signal) { // POR ENQUANTO ASSIM
	if (signal == SIGINT) {
		close(server_socket);
		exit(0);
	}
}