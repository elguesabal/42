#include "header.h"

/// @brief FUNCAO Q SPLITA USANDO '\n', REMOVE TODOS OS \r E ARMAZENA O RESULTADO DENTRO DE server.bufferStrs
void Server::splitMessage(void) {
	this->bufferStr.erase(std::remove(this->bufferStr.begin(), this->bufferStr.end(), '\r'), this->bufferStr.end()); // REMOVE TODOS OS \r

	this->bufferStrs.clear();

	std::istringstream stream(this->bufferStr);
	std::string line;

	while(std::getline(stream, line, '\n')) {
		this->bufferStrs.push_back(line);
	}
}

std::string Server::toUpper(std::string &str) {
	char ret[str.size() + 1];

	for (unsigned int i = 0; i < str.size(); i++) {
		ret[i] = ((str[i] >= 'a' && str[i] <= 'z') ? str[i] - 32 : str[i]);
	}
	ret[str.size()] = '\0';

// std::cout << "retornou: " << "'" << ret << "'" << std::endl;

	return (ret);
}


// std::string teste(void) {
// 	char str[3];

// 	str[0] = 'a';
// 	str[1] = 'b';
// 	str[2] = 'c';

// 	return str;
// }