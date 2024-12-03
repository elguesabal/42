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
/// @param i INDICE EM REFERENTE A POSICAO DO CLIENTE EM A SER REMOVIDO
void delete_client(std::vector<pollfd> &fds, std::vector<Client> &clients, unsigned int i, Client &client) {
	std::cout << "Conexao encerrada do ip " << inet_ntoa(clients[i - 1].client.sin_addr) << " na porta " << ntohs(clients[i - 1].client.sin_port) << std::endl;
	// fds.erase(fds.begin() + i);
	// clients[i - 1].close_client();
	// clients.erase(clients.begin() + i - 1);


	std::vector<Client>::iterator it = std::find(clients.begin(), clients.end(), client); // PQP TAVA FATANDO INCLUIR A BIBLIOTECA <algorithm> POR ISSO TAVA DANDO ERRO NA COMPILACAO
	// if (client == client)
	// 	std::cout << "foi" << std::endl;

	// int index = it - clients.begin();
	// std::cout << "index: " << index << " i: " << i << std::endl;

	// fds.erase(std::find(fds.begin(), fds.end(), client.pfd)); // A CLASSE TEM O OPERADOR == DEFINIDO?? VOU TER Q FAZER O OPERADOR DE ==
	clients[std::find(clients.begin(), clients.end(), client.pfd.fd) - clients.begin()].close_client();
	clients.erase(std::find(clients.begin(), clients.end(), client.pfd.fd));


	// std::vector<int> teste;
	// teste.push_back(1);
	// teste.push_back(2);
	// teste.push_back(3);

	// std::vector<int>::iterator it = std::find(teste.begin(), teste.end(), 2);
	// std::cout << "teste: " << *it << std::endl;


(void)fds;
(void)clients;
(void)i;
(void)client;
(void)it;
}

/// @brief FUNCAO Q ENCAMINHA COMO O BUFFER RECEBIDO POR UM CLIENTE ESPECIFICO VAI SER TRATADO
/// @param client REFERENCIA Q CONTEM AS INFORMACOES DO CLIENTE
/// @param fds PILHA RESPONSAVEL POR TODOS OS FDS ABERTOS (INCLUINDO O PRIMEIRO Q E O SOCKET DO SERVIDOR)
/// @param buffer 
void new_buffer(Server &server, Client &client, std::vector<pollfd> &fds, std::string buffer) {
	if (client.auth == false) {
		buffer.erase(buffer.size() - 1);
		if (buffer == server.password) {
			client.auth = true;
			send(client.pfd.fd, "Bem vindo ao servidor!\n", 23, 0);
		} else {
			send(client.pfd.fd, "Senha incorreta! Digite novamente: ", 35, 0);
			// client.password_attempts++;
			// (client.password_attempts < 3) ? client.password_attempts++ : delete_client(???);
			// AKI NAO TENHO UM INDICE PARA PASSAR COMO ARGUMENTO ENTAO VOU TER Q FAZER UMA BUSCA delete_client() DENTRO DO ARRAY DE FD
			// EU POSSO ENVIAR UMA MENSAGEM PARA UM SOCKET EM Q O CLIENTE JA FECHOU A CONEXAO???
		}
	} else {
		for (unsigned int i = 1; i < fds.size(); i++) {
			if (fds[i].fd != client.pfd.fd) {
				send(fds[i].fd, buffer.c_str(), buffer.size(), 0);
			}
		}
	}
}

// bool authentication(Client &client) {

// }