#include "header.h"

/// @brief CRIA UM NOVO CLIENTE DPS Q A FUNCAO poll DETECTAR UM EVENTO DE NOVA CONEXAO (PREENCHE TODAS AS VARIAVEIS DENTRO DA CLASSE COM BASE NA LEITURA DO SOCKET DO SERVIDOR)
Client::Client(int server_socket) {
	// int new_socket; Q BURRO EU POSSO USAR this->pfd.fd
	// struct sockaddr_in client_address; Q BURRO EU POSSO USAR DIRETAMENTE A VARIAVEL DA CLASSE
	// socklen_t client_address_len = sizeof(client_address);

	socklen_t client_address_len = sizeof(this->client);

	// new_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
	this->pfd.fd = accept(server_socket, (struct sockaddr *)&this->client, &client_address_len);
	if (this->pfd.fd == -1) {
		std::cerr << "Erro ao aceitar conexão" << std::endl;
		close(server_socket);
		exit(-1);
	}

	std::cout << "Conexao aceita do ip " << inet_ntoa(this->client.sin_addr) << " na porta " << ntohs(this->client.sin_port) << std::endl;
	send(this->pfd.fd, "Digite a senha: ", 16, 0);

	// struct pollfd fd; Q BURRO EU CRIAVA UMA NOVA VARIAVEL SENDO Q EU PODIA GRAVAR DIRETO NA VARIAVEL DA CLASSE
	// fd.fd = new_socket;
	// fd.events = POLLIN;
	// this->pfd = fd;

	// this->client = client_address;
	// this->pfd.fd = new_socket;
	this->pfd.events = POLLIN;
	this->auth = false;
	this->password_attempts = 0;
}

Client::~Client(void) {
	// this->delete_client();
}

bool Client::operator == (const Client &client) const {
	return (this->pfd.fd == client.pfd.fd); // SERA Q VERIFICAR APENAS POR UM IDENTIFICADOR UNICO BASTA???
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