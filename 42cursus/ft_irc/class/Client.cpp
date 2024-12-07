#include "header.h"

/// @brief CRIA UM NOVO CLIENTE DPS Q A FUNCAO poll DETECTAR UM EVENTO DE NOVA CONEXAO (PREENCHE TODAS AS VARIAVEIS DENTRO DA CLASSE COM BASE NA LEITURA DO SOCKET DO SERVIDOR)
/// @param sever REFERENCIA Q CONTEM AS INFORMACOES DO SERVIDOR
Client::Client(Server &server) {
	socklen_t client_address_len = sizeof(this->client);
	this->pfd.fd = accept(server.pfd.fd, (struct sockaddr *)&this->client, &client_address_len);
	if (this->pfd.fd == -1) {
		std::cerr << "Erro ao aceitar conexão" << std::endl;
		close(server.pfd.fd);
		exit(-1);
	}
	std::cout << "Conexao aceita do ip " << inet_ntoa(this->client.sin_addr) << " na porta " << ntohs(this->client.sin_port) << std::endl;
	send(this->pfd.fd, "Digite a senha: ", 16, 0);
	this->pfd.events = POLLIN;
	this->auth = false;
	this->password_attempts = 0;
}

Client::~Client(void) {
	// this->delete_client();
	// std::cout << "testando destrutor" << std::endl; // POR CAUSA DE ESTAR ARMAZENADO EM UM VECTOR C

	// std::cout << "testando o delete" << std::endl;
	std::cout << "Conexao encerrada do ip " << inet_ntoa(this->client.sin_addr) << " na porta " << ntohs(this->client.sin_port) << std::endl;
	close(this->pfd.fd);
}

bool Client::operator == (const Client &client) const {
	return (this->pfd.fd == client.pfd.fd); // SERA Q VERIFICAR APENAS POR UM IDENTIFICADOR UNICO BASTA???
}

// void Client::closeClient(void) {
// 	// if (this->pfd.fd != -1) {
// 	// 	// std::cout << "fechando o fd" << std::endl;
// 	// 	close(this->pfd.fd);
// 	// 	this->pfd.fd = -1;
// 	// }

// 	close(this->pfd.fd);
// }

std::string Client::ip(void) const {
	return ("vampeta");
}

unsigned short Client::port(void) const {
	return (5);
}