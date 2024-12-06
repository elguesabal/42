#include "header.h"

/// @brief FUNCAO Q COMECA A MONITORAR TODOS OS FDS USANDO poll() E GERENCIA QUAL O DESTINO DO DADO RECEBIDO (SE E UM NOVO CLIENTE, UM CLIENTE DESCONECTANDO)
/// @param sever REFERENCIA Q CONTEM AS INFORMACOES DO SERVIDOR
void listener(Server &server) {
	while (true) {
		int ret = poll(server.fds.data(), server.fds.size(), -1);
		if (ret == -1) {
			std::cout << "erro no poll" << std::endl;
			exit(1);
		} else if (server.fds[0].revents & POLLIN) {
			// new_client(server);
			server.new_client();
		} else {
			for (unsigned int i = 1; i < server.fds.size(); i++) {
				if (server.fds[i].revents & POLLIN) {
					memset(server.bufferChar, 0, 1024);
					ssize_t bytes_received = recv(server.fds[i].fd, server.bufferChar, 99, 0);
					server.bufferStr = server.bufferChar;
					if (bytes_received > 0) {
						new_buffer(server, server.clients[i - 1]);
					} else if (bytes_received == 0) {
						// delete_client(server, server.clients[i - 1]);
						server.delete_client(server.clients[i - 1]);
					} else if (bytes_received < 0) {
						std::cerr << "Erro ao receber mensagem" << std::endl;
					}
					break;
				}
			}
		}
	}
}