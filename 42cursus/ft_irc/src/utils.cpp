// #include "header.h"

// /// @brief FUNCAO Q SPLITA USANDO '\n', REMOVE TODOS OS \r E ARMAZENA O RESULTADO DENTRO DE server.bufferStrs
// /// @param server REFERENCIA Q CONTEM AS INFORMACOES DO SERVIDOR
// void splitMessage(Server &server) {
// 	server.bufferStr.erase(std::remove(server.bufferStr.begin(), server.bufferStr.end(), '\r'), server.bufferStr.end()); // REMOVE TODOS OS \r

// 	server.bufferStrs.clear();

// 	std::istringstream stream(server.bufferStr);
// 	std::string line;

// 	while(std::getline(stream, line, '\n')) {
// 		server.bufferStrs.push_back(line);
// 	}
// }


// void toUpper(std::string &str, std::vector<std::string> ) {

// }



                        // CAIU EM DESUSO PQ FUI SOCANDO TUDO NA CLASS Server