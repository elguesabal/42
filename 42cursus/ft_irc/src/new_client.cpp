#include "header.h"

/// @brief ESPERA E CRIA NOVOS CLIENTES
/// @return RETORNA OS DADOS DE UM NOVO CLIENTE
Client new_client(void) {
    int new_socket;
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);

    new_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
    if (new_socket == -1) {
        std::cerr << "Erro ao aceitar conexão" << std::endl;
        close(server_socket);
        exit(-1);
    } else {
		// std::cout << "conexao aceita" << std::endl;
		std::cout << "Conexao aceita do ip: " << inet_ntoa(client_address.sin_addr) << " na porta " << ntohs(client_address.sin_port) << std::endl;
	}

    // Client client(new_socket, client_address);
    return (Client(new_socket, client_address));
}