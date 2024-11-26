#include "header.h"

int authPassword(int client_socket, char *passwordServer) {
	char buffer[100];
	std::string passwordClient;
	int cout = 0;

	do {
		if (cout == 0) {
			send(client_socket, "Senha: ", 7, 0);
		}else if (cout < 3) {
			send(client_socket, "Senha incorreta, tente novamente: ", 34, 0);
		} else {
			std::cout << "Numero maximo de tentativas alcancado" << std::endl;
			send(client_socket, "Numero maximo de tentativas alcancado\n", 38, 0);
			// COMO EU FECHO A CONEXAO DO CLIENTE?
			return (-1);
		}

		memset(buffer, 0, 100);
		ssize_t bytes_received = recv(client_socket, buffer, 99, 0);

		if (bytes_received < 0) {
			std::cerr << "Erro ao receber senha" << std::endl;
			return (-1);
		}

		if (bytes_received == 0) {
			std::cout << "Conexao encerrada pelo cliente" << std::endl;
			return (-1);
		}

		++cout;
		passwordClient = buffer;
		// std::cout << "testando o paranaue: " << buffer << std::endl;
		passwordClient.erase(passwordClient.size() - 1); // TO RETIRANDO O \n NO FIM DA STRING
	} while (passwordServer != passwordClient);
// std::cout << "O cliente digitou a senha certa" << std::endl;
	return (1);
}