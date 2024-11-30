#include "header.h"

/// @brief CRIA UM NOVO CLIENTE DPS Q A FUNCAO poll DETECTAR UM EVENTO DE NOVA CONEXAO (PREENCHE TODAS AS VARIAVEIS DENTRO DA CLASSE COM BASE NA LEITURA DO SOCKET DO SERVIDOR)
Client::Client(int server_socket) {
	int new_socket;
	struct sockaddr_in client_address;
	socklen_t client_address_len = sizeof(client_address);

	new_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
	if (new_socket == -1) {
		std::cerr << "Erro ao aceitar conexão" << std::endl;
		close(server_socket);
		exit(-1);
	} else {
		std::cout << "Conexao aceita do ip " << inet_ntoa(client_address.sin_addr) << " na porta " << ntohs(client_address.sin_port) << std::endl;
	}

	struct pollfd fd;
	fd.fd = new_socket;
	fd.events = POLLIN;

	this->client = client_address;
	// this->socket = new_socket;
	this->pfd = fd;
	this->auth = false;
	this->password_attempts = 0;
}

// Client::Client(int socket, sockaddr_in client, pollfd pfd) : client(client), pfd(pfd) {

// }

Client::~Client(void) {
	// this->delete_client();
}

void Client::close_client(void) {
	if (this->pfd.fd != -1) {
		// std::cout << "fechando o fd" << std::endl;
		close(this->pfd.fd);
		this->pfd.fd = -1;
	}
}

std::string Client::ip(void) const {
	return ("vampeta");
}

unsigned short Client::port(void) const {
	return (5);
}