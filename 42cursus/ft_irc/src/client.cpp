// #include "header.h"

/// @brief CRIA UM NOVO CLIENTE E SALVA DENTRO DAS DUAS PILHAS
/// @param sever REFERENCIA Q CONTEM AS INFORMACOES DO SERVIDOR
// void new_client(Server &server) { // ESSA FUNCAO VIROU METODO DA CLASSE Server
//     Client new_client(server);
// 	server.fds.push_back(new_client.pfd);
// 	server.clients.push_back(new_client);

// 	// VOU TER Q ALOCAR MEMORIA DINAMICAMENTE PARA NAO FICAR CLIENTES Q JA DESCONECTARAM SALVO NA MEMORIA RAM
// }

/// @brief REMOVE UM CLIENTE CLIENTE DA PILHA DE FD E DA PILHA DE CLIENTES
/// @param sever REFERENCIA Q CONTEM AS INFORMACOES DO SERVIDOR
/// @param client REFERENCIA COM OS DADOS DO CLIENTE PARA COMPARACAO
// void delete_client(Server &server, Client &client) { // ESSA FUNCAO VIROU METODO DA CLASSE Server
// 	unsigned int i = std::find(server.clients.begin(), server.clients.end(), client) - server.clients.begin() + 1;

// 	std::cout << "Conexao encerrada do ip " << inet_ntoa(server.clients[i - 1].client.sin_addr) << " na porta " << ntohs(server.clients[i - 1].client.sin_port) << std::endl;
// 	server.fds.erase(server.fds.begin() + i);
// 	server.clients[i - 1].close_client();
// 	server.clients.erase(server.clients.begin() + i - 1);
// }

/// @brief FUNCAO Q ENCAMINHA COMO O BUFFER RECEBIDO POR UM CLIENTE ESPECIFICO VAI SER TRATADO
/// @param sever REFERENCIA Q CONTEM AS INFORMACOES DO SERVIDOR
/// @param client REFERENCIA Q CONTEM AS INFORMACOES DO CLIENTE
// void new_buffer(Server &server, Client &client) { // ESSA FUNCAO VIROU METODO DA CLASSE Server
// 	if (client.auth == false) {
// 		authentication(server, client);
// 	} else {
// 		for (unsigned int i = 1; i < server.fds.size(); i++) {
// 			if (server.fds[i].fd != client.pfd.fd) {
// 				send(server.fds[i].fd, server.bufferStr.c_str(), server.bufferStr.size(), 0);
// 			}
// 		}
// 	}

// 	// else if (client.nickname) {
// 	// 	// PROXIMO PASSO
// 	// 	// TALVEZ A PROXIMA COISA Q EU FACA SEJA MUDAR A MEMORIA PARA DINAMICA PARA OS CLIENTES
// 	// } 
// }

/// @brief FUNCAO Q LIDA COM INSERCAO DE SENHA QUANDO O CLIENTE SE CONECTA
/// @param sever REFERENCIA Q CONTEM AS INFORMACOES DO SERVIDOR
/// @param client REFERENCIA Q CONTEM AS INFORMACOES DO CLIENTE
// void authentication(Server &server, Client &client) { // ESSA FUNCAO VIROU METODO DA CLASSE Server
// 	server.bufferStr.erase(server.bufferStr.size() - 1);
// 	if (server.bufferStr == server.password) {
// 		client.auth = true;
// 		send(client.pfd.fd, "Bem vindo ao servidor!\n", 23, 0);
// 	} else {
// 		if (client.password_attempts > 1) {
// 			send(client.pfd.fd, "Limite de tentativas excedidas. Aguarde e tente novamente mais tarde\n", 69, 0);
// 			// delete_client(server, client);
// 			server.delete_client(client);
// 		} else {
// 			send(client.pfd.fd, "Senha incorreta! Digite novamente: ", 35, 0);
// 			client.password_attempts++;
// 		}
// 	}
// }