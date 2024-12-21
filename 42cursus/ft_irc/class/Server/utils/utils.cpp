#include "header.h"

bool hasInvalidNewline(std::string str) {
	size_t pos = 0;

	while ((pos = str.find('\n', pos)) != std::string::npos) {
		if (pos == 0 || str[pos - 1] != '\r') {
			return true; // Encontrou um "\n" sem "\r" antes dele
		}
		++pos; // Avançar para procurar o próximo "\n"
	}

	return false; // Não encontrou nenhum "\n" inválido
}

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
		if (line[0] == ':') {
			line.erase(0, 1);
			std::string lastLine;
			std::getline(stream, lastLine);
			line += (lastLine.empty()) ? "" : " " + lastLine;
		}
		this->argsCmd.push_back(line);
	}
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