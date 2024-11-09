#include "header.h"

int validation(int argc, char **argv) {
	if (argc != 3) {
		std::cout << "Numero de argumentos invalido" << std::endl;
		return (1);
	}

	if (strlen(argv[1]) > 15) {
		std::cout << "Primeiro argumento deve conter apenas um ip" << std::endl;
		return (1);
	}
	for (int i = 0; argv[1][i]; i++) {
		if (argv[1][i] != '.' && (argv[1][i] < '0' || argv[1][i] > '9')) {
			std::cout << "Primeiro argumento deve conter apenas um ip" << std::endl;
			return (1);
		}
	}

	if (strlen(argv[2]) > 4) {
		std::cout << "O segundo argumento deve conter apenas uma porta" << std::endl;
		return (1);
	}
	for (int i = 0; argv[2][i]; i++) {
		if (argv[2][i] < '0' || argv[2][i] > '9') {
			std::cout << "O segundo argumento deve conter apenas uma porta" << std::endl;
			return (1);
		}
	}
	return (0);
}

int server(int port) {
	int server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket == -1) {
		std::cerr << "Erro ao criar o socket" << std::endl;
		return (-1);
	}

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(port);
	if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
		std::cerr << "Erro ao associar o socket ao endereço e porta" << std::endl;
		return (-1);
	}

	if (listen(server_socket, 5)) {
		std::cerr << "Erro ao colocar o socket em modo de escuta" << std::endl;
		close(server_socket);
		return (-1);
	}

	return (server_socket);
}

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

void ctrlC(int signal) { // POR ENQUANTO ASSIM
	if (signal == SIGINT) {
		close(server_socket);
		exit(0);
	}
}

int main(int argc, char **argv) {
	if (validation(argc, argv))
		return (0);
	server_socket = server(std::atoi(argv[2]));
	if (server_socket == -1)
		return (-1);



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

std::signal(SIGINT, ctrlC); // CAGUEI PRO sigaction()



	// std::vector<int> client_sockets;
	int new_socket;
	struct sockaddr_in client_address;
	socklen_t client_address_len = sizeof(client_address);
	while (true) {
		new_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
		if (new_socket == -1) {
			std::cerr << "Erro ao aceitar conexão" << std::endl;
			close(server_socket);
			return (-1);
		}

		// client_sockets.push_back(new_socket);
		std::cout << "Conexão aceita do cliente: " << inet_ntoa(client_address.sin_addr) << " na porta " << ntohs(client_address.sin_port) << std::endl;

		send(new_socket, "vampeta", 7, 0);
	}

	// AKI EU DEVERIA FECHAR O SERVIDOR MAS NESSE CASO O LOOP E INFINITO
	return (0);
}