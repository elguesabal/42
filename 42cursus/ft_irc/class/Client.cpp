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
	this->pfd.events = POLLIN;
}

/// @brief RESPONSAVEL POR FECHAR O FD DO CLIENTE
Client::~Client(void) {
	std::cout << "Conexao encerrada do ip " << inet_ntoa(this->client.sin_addr) << " na porta " << ntohs(this->client.sin_port) << std::endl;
	close(this->pfd.fd);
}