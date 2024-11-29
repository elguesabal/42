#include "header.h"

/// @brief ESPERA E CRIA NOVOS CLIENTES
/// @return RETORNA OS DADOS DE UM NOVO CLIENTE
// Client new_client(void) {
// 	int new_socket;
// 	struct sockaddr_in client_address;
// 	socklen_t client_address_len = sizeof(client_address);

// 	new_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
// 	if (new_socket == -1) {
// 		std::cerr << "Erro ao aceitar conexão" << std::endl;
// 		close(server_socket);
// 		exit(-1);
// 	} else {
// 		std::cout << "Conexao aceita do ip: " << inet_ntoa(client_address.sin_addr) << " na porta " << ntohs(client_address.sin_port) << std::endl;
// 	}

// 	struct pollfd pfd;
// 	pfd.fd = new_socket;
// 	pfd.events = POLLIN;
// 	return (Client(new_socket, client_address, pfd));
// }



/// @brief CRIA UM NOVO CLIENTE E SALVA DENTRO DAS DUAS PILHAS
/// @param fds PILHA RESPONSAVEL POR TODOS OS FDS ABERTOS (INCLUINDO O PRIMEIRO Q E O SOCKET DO SERVIDOR)
/// @param clients PILHA RESPONSALVEL POR TODOS OS CLIENTES (CADA POSICAO E UMA CLASSE CONTENDO TODAS AS INFORMACOES DO CLIENTE)
void new_client(std::vector<pollfd> &fds, std::vector<Client> &clients) {
    Client new_client;
	fds.push_back(new_client.pfd);
	clients.push_back(new_client);
}

/// @brief REMOVE UM CLIENTE CLIENTE DA PILHA DE FD E DA PILHA DE CLIENTES
/// @param fds PILHA RESPONSAVEL POR TODOS OS FDS ABERTOS (INCLUINDO O PRIMEIRO Q E O SOCKET DO SERVIDOR)
/// @param clients PILHA RESPONSALVEL POR TODOS OS CLIENTES (CADA POSICAO E UMA CLASSE CONTENDO TODAS AS INFORMACOES DO CLIENTE)
/// @param i INDICE EM REFERENTE A POSICAO DO CLIENTE EM A SER REMOVIDO
void delete_client(std::vector<pollfd> &fds, std::vector<Client> &clients, unsigned int i) {
	fds.erase(fds.begin() + i);
	clients[i - 1].close_client();
	clients.erase(clients.begin() + i - 1);
	std::cout << "Conexao encerrada pelo cliente" << std::endl;
}