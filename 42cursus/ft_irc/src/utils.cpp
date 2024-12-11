#include "header.h"

/// @brief FUNCAO Q SPLITA USANDO '\n' E ARMAZENA O RESULTADO DENTRO DE server.bufferStrs
/// @param server REFERENCIA Q CONTEM AS INFORMACOES DO SERVIDOR
void splitMessage(Server &server) {
	server.bufferStrs.clear();

	std::istringstream stream(server.bufferStr);
	std::string line;

	while(std::getline(stream, line, '\n')) {
		server.bufferStrs.push_back(line);
	}
}