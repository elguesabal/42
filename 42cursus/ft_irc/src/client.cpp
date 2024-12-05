#include "header.h"

/// @brief CRIA UM NOVO CLIENTE E SALVA DENTRO DAS DUAS PILHAS
/// @param fds PILHA RESPONSAVEL POR TODOS OS FDS ABERTOS (INCLUINDO O PRIMEIRO Q E O SOCKET DO SERVIDOR)
/// @param clients PILHA RESPONSALVEL POR TODOS OS CLIENTES (CADA POSICAO E UMA CLASSE CONTENDO TODAS AS INFORMACOES DO CLIENTE)
void new_client(std::vector<pollfd> &fds, std::vector<Client> &clients, int server_socket) {
    Client new_client(server_socket);
	fds.push_back(new_client.pfd);
	clients.push_back(new_client);

	// clients.emplace_back(Client(server_socket)); ESSA BAGACA DE .emplace_back() SO FUNCIONA NO C++11
	// VOU TER Q ALOCAR MEMORIA DINAMICAMENTE PARA NAO FICAR CLIENTES Q JA DESCONECTARAM SALVO NA MEMORIA RAM
}

/// @brief REMOVE UM CLIENTE CLIENTE DA PILHA DE FD E DA PILHA DE CLIENTES
/// @param fds PILHA RESPONSAVEL POR TODOS OS FDS ABERTOS (INCLUINDO O PRIMEIRO Q E O SOCKET DO SERVIDOR)
/// @param clients PILHA RESPONSALVEL POR TODOS OS CLIENTES (CADA POSICAO E UMA CLASSE CONTENDO TODAS AS INFORMACOES DO CLIENTE)
/// @param client REFERENCIA COM OS DADOS DO CLIENTE PARA COMPARACAO
void delete_client(std::vector<pollfd> &fds, std::vector<Client> &clients, Client &client) {
	unsigned int i = std::find(clients.begin(), clients.end(), client) - clients.begin() + 1;

	std::cout << "Conexao encerrada do ip " << inet_ntoa(clients[i - 1].client.sin_addr) << " na porta " << ntohs(clients[i - 1].client.sin_port) << std::endl;
	fds.erase(fds.begin() + i);
	clients[i - 1].close_client();
	clients.erase(clients.begin() + i - 1);
}

/// @brief FUNCAO Q ENCAMINHA COMO O BUFFER RECEBIDO POR UM CLIENTE ESPECIFICO VAI SER TRATADO
/// @param sever REFERENCIA Q CONTEM AS INFORMACOES DO SERVIDOR
/// @param clients REFERENCIA Q CONTEM UM ARRAY COM AS INFORMACOES DE TODOS CLIENTES
/// @param client REFERENCIA Q CONTEM AS INFORMACOES DO CLIENTE
/// @param fds PILHA RESPONSAVEL POR TODOS OS FDS ABERTOS (INCLUINDO O PRIMEIRO Q E O SOCKET DO SERVIDOR)
/// @param buffer NOVO CONJUNTO DE DADO RECEBIDO A SER ANALIZADO
void new_buffer(Server &server, std::vector<Client> &clients, Client &client, std::vector<pollfd> &fds, std::string buffer) {
	if (client.auth == false) {
		authentication(clients, client, fds, buffer, server.password);
	} else if (client.nickname) {
		// PROXIMO PASSO
		// TALVEZ A PROXIMA COISA Q EU FACA SEJA MUDAR A MEMORIA PARA DINAMICA PARA OS CLIENTES
	} else {
		for (unsigned int i = 1; i < fds.size(); i++) {
			if (fds[i].fd != client.pfd.fd) {
				send(fds[i].fd, buffer.c_str(), buffer.size(), 0);
			}
		}
	}
}

/// @brief FUNCAO Q LIDA COM INSERCAO DE SENHA QUANDO O CLIENTE SE CONECTA
/// @param clients REFERENCIA Q CONTEM UM ARRAY COM AS INFORMACOES DE TODOS CLIENTES
/// @param client REFERENCIA Q CONTEM AS INFORMACOES DO CLIENTE
/// @param fds PILHA RESPONSAVEL POR TODOS OS FDS ABERTOS (INCLUINDO O PRIMEIRO Q E O SOCKET DO SERVIDOR)
/// @param buffer SENHA PASSADA PELO CLIENTE
/// @param password SENHA DO SERVIDOR Q DEVE SER COMPARADA COM A DO CLIENTE
void authentication(std::vector<Client> &clients, Client &client, std::vector<pollfd> &fds, std::string &buffer, std::string &password) {
	buffer.erase(buffer.size() - 1);
	if (buffer == password) {
		client.auth = true;
		send(client.pfd.fd, "Bem vindo ao servidor!\n", 23, 0);
	} else {
		if (client.password_attempts > 1) {
			send(client.pfd.fd, "Limite de tentativas excedidas. Aguarde e tente novamente mais tarde\n", 69, 0);
			delete_client(fds, clients, client);
		} else {
			send(client.pfd.fd, "Senha incorreta! Digite novamente: ", 35, 0);
			client.password_attempts++;
		}
	}
}