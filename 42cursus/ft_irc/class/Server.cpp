#include "header.h"

/// @brief CONSTRUTOR Q INICIALIZA O SERVIDOR
/// @param port PORTA EM Q O SERVIDOR ESTARA ABERTO
/// @param password SENHA Q O SERVIDOR ADOTARA
Server::Server(int port, char *password) {
	this->pfd.fd = socket(AF_INET, SOCK_STREAM, 0);
	// server_socket = this->pfd.fd;
	if (this->pfd.fd == -1) {
		std::cerr << "Erro ao criar o socket" << std::endl;
		exit(1);
	}
	int opt = 1;
	if (setsockopt(this->pfd.fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
		std::cerr << "Erro ao definir opção de socket" << std::endl;
		exit(1);
	}
	this->server.sin_family = AF_INET;
	this->server.sin_addr.s_addr = INADDR_ANY;
	this->server.sin_port = htons(port);
	if (bind(this->pfd.fd, (struct sockaddr *)&this->server, sizeof(this->server)) == -1) {
		std::cerr << "Erro ao associar o socket ao endereço e porta" << std::endl;
		exit(1);
	}
	if (listen(this->pfd.fd, 5)) {
		std::cerr << "Erro ao colocar o socket em modo de escuta" << std::endl;
		close(this->pfd.fd);
		exit(1);
	}
	fcntl(this->pfd.fd, F_SETFL, O_NONBLOCK);
	this->pfd.events = POLLIN;
	this->fds.push_back(this->pfd);
	this->password = password;
	std::cout << "Servidor iniciado na porta: " << port << std::endl << "Senha: " << password << std::endl;
}

Server::~Server(void) {
	// close(this->pfd.fd); SE EU USO CTRL+C ESSA BAGACA NAO E CHAMADA
}

/// @brief CRIA UM NOVO CLIENTE E SALVA O FD NO VECTOR DE FDS E O CLIENTE NO VECTOR DE CLIENTES
void Server::new_client(void) {
    Client new_client(*this);
	this->fds.push_back(new_client.pfd);
	this->clients.push_back(new_client);
}

/// @brief REMOVE UM CLIENTE DO FD NO VECTOR DE FDS E O CLIENTE NO VECTOR DE CLIENTES
void Server::delete_client(Client &client) {
	unsigned int i = std::find(this->clients.begin(), this->clients.end(), client) - this->clients.begin() + 1;

	std::cout << "Conexao encerrada do ip " << inet_ntoa(this->clients[i - 1].client.sin_addr) << " na porta " << ntohs(this->clients[i - 1].client.sin_port) << std::endl;
	this->fds.erase(this->fds.begin() + i);
	this->clients[i - 1].close_client();
	this->clients.erase(this->clients.begin() + i - 1);
}