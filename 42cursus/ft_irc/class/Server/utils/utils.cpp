#include "header.h"

/// @brief VERIFICA SE OUVE QUEBRA DO PROTOCOLO IRC
/// @brief VERIFICA SE O FIM DA TRANSMISSAO TERMINA COM "\r\n"
/// @brief VERIFICA APENAS SE EXISTE "\n" SEM "\r"
bool Server::invalidLine(void) {
	if (this->cmd.size() < 2 || this->cmd[this->cmd.size() - 2] != '\r' || this->cmd[this->cmd.size() - 1] != '\n') {
		return (true);
	}

	for (unsigned int i = 1; i < this->cmd.size(); i++) {
        if (this->cmd[i] == '\n') {
            if (i == 0 || this->cmd[i - 1] != '\r') {
                return (true);
            }
        }
	}

	return (false);
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

void Server::authentication(void) {
	this->resClient(":" + this->getIp() + " 001 " + this->client->nick + " :Bem-vindo ao servidor ft_irc, " + this->client->nick + "!" + this->client->user + "@" + this->client->getIp());
	this->resClient(":" + this->getIp() + " 002 " + this->client->nick + " :O host do servidor é " + this->getIp() + ", rodando na versão 42");
	this->resClient(":" + this->getIp() + " 003 " + this->client->nick + " :Este servidor foi criado dia " + this->getDate() + " às " + this->getTime());
	this->client->auth = true;
}