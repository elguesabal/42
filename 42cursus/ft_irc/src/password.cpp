#include "header.h"

/// @brief AUTENTICA O CLIENTE COM BASE NA SENHA DIGITADA
/// @param client_socket FD DE CONEXAO DO CLIENTE
/// @param passwordServer SENHA PARA ACESSAR O SERVIDOR
/// @return RETORNA 1 EM CASO DE SENHA INSERICA CORRETAMENTE E -1 CASO O CLIENTE DIGITE A SENHA ERRADA 3 VEZES OU ALGUM OUTRO ERRO OCORRA
int authPassword(int client_socket, char *passwordServer) {
	char buffer[100];
	std::string passwordClient;
	int cout = 0;

	do {
		if (cout == 0) {
			send(client_socket, "Senha: ", 7, 0);
		} else if (cout < 3) {
			send(client_socket, "Senha incorreta, tente novamente: ", 34, 0);
		} else {
			std::cout << "O cliente errou a senha 3 vezes" << std::endl;
			send(client_socket, "Numero maximo de tentativas alcancado\n", 38, 0);
			close(client_socket);
			return (-1);
		}

		memset(buffer, 0, 100);
		ssize_t bytes_received = recv(client_socket, buffer, 99, 0);
		if (bytes_received == 0) {
			std::cout << "Conexao encerrada pelo cliente" << std::endl;
			return (-1);
		} else if (bytes_received < 0) {
			std::cerr << "Erro ao receber senha" << std::endl;
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