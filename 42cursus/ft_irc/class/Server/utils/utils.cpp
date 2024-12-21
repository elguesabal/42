#include "header.h"

/// @brief METODO Q SPLITA VARIOS COMANDOS USANDO '\n', REMOVE TODOS OS \r E ARMAZENA O RESULTADO DENTRO DE server.cmds
void Server::splitCmds(void) {
	this->cmd.erase(std::remove(this->cmd.begin(), this->cmd.end(), '\r'), this->cmd.end()); // REMOVE TODOS OS \r

	this->cmds.clear();

	std::istringstream stream(this->cmd);
	std::string line;

	while(std::getline(stream, line, '\n')) {
		this->cmds.push_back(line);
	}
}

/// @brief METODO Q SPLITA UM COMANDO EM ARGUMENTOS USANDO ' ' E REMOVE O \r
/// @return RETORNA UM VECTOR COM OS ARGUMENTOS
void Server::splitCmd(void) {
	this->argsCmd.clear();

	std::istringstream stream(this->cmd);
	std::string line;

	while(std::getline(stream, line, ' ')) {
		this->argsCmd.push_back(line);
	}

	// std::cout << "usando splitComand: '" << this->cmd << "'" << std::endl;
}

/// @brief METODO PASSA TODOS OS CARACTERES PARA MAIUSCULO
/// @return RETORNA UMA NOVA STRING EM MAIUSCULO
std::string Server::toUpper(std::string &str) {
	char ret[str.size() + 1];

	for (unsigned int i = 0; i < str.size(); i++) {
		ret[i] = ((str[i] >= 'a' && str[i] <= 'z') ? str[i] - 32 : str[i]);
	}
	ret[str.size()] = '\0';

	return (ret);
}