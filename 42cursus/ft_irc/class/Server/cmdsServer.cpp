#include "header.h"

/// @brief METODO Q RESPONDE AO COMANDO "CAP"
void Server::CAP(void) {
	if (this->cmd == "CAP LS 302") {
		this->resClient(":" + this->getIp() + " CAP * LS");
	}
}

/// @brief METODO Q LIDA COM A VALIDACAO DA SENHA
void Server::PASS(void) {
	if (this->client->authPass == true) {
		this->resClient(":" + this->getIp() + " " + ERR_ALREADYREGISTRED + " " + this->client->nick + " :Comando não autorizado (já registrado)"); // Unauthorized command (already registered)
	} else if (this->argsCmd.size() < 2) {
		this->resClient(":" + this->getIp() + " " + ERR_NEEDMOREPARAMS + " * PASS :Parâmetros insuficientes"); // Not enough parameters
		this->deleteClient();
	} else if (this->cmd.substr(5) != this->password) {
		this->resClient(":" + this->getIp() + " " + ERR_PASSWDMISMATCH + " * :Senha incorreta"); // Password incorrect
		this->deleteClient();
	} else {
		this->client->authPass = true;
	}
}

/// @brief METODO RESPONSAVEL POR VERIFICAR SE O NICK ESTA DISPONIVEL SALVAR
void Server::NICK(void) {
	if (this->client->authPass == false) {
		this->resClient(":" + this->getIp() + " " + ERR_PASSWDMISMATCH + " * :Senha necessária"); // Password required
		this->deleteClient();
	} else if (this->argsCmd.size() < 2) {
		this->resClient(":" + this->getIp() + " " + ERR_NONICKNAMEGIVEN + " * :Nenhum apelido fornecido"); // No nickname 
	} else if (this->nickInvalid(this->argsCmd[1])) {
		// std::cout << "nick proibido" << std::endl;
		this->resClient(":" + this->getIp() + " " + ERR_ERRONEUSNICKNAME " " + this->client->nick + " " + this->argsCmd[1] + " :Apelido inválido"); // Erroneous nickname
	} else if (this->nickInUse(this->argsCmd[1])) { // DEVO IGNORAR O CLIENTE CASO ELE TENTE ALTERAR O NICK PARA O PROPRIO NICK??
		// std::cout << "nick em uso" << std::endl;
		this->resClient(":" + this->getIp() + " " + ERR_NICKNAMEINUSE + " " + this->client->nick + " " + this->argsCmd[1] + " :O apelido já está em uso"); // Nickname is already in use
	} else if (this->client->authNick == true) {
		// std::cout << "nick livre autenticado" << std::endl;
		this->resClient(":" + this->client->nick + " NICK :" + this->argsCmd[1]);
		this->nickClient.erase(this->client->nick);
		this->nickClient[this->argsCmd[1]] = this->client;
		this->client->nick = this->argsCmd[1];
	} else {
		// std::cout << "nick livre sem autenticar" << std::endl;
		this->nickClient[this->argsCmd[1]] = this->client;
		this->client->nick = this->argsCmd[1];
		this->client->authNick = true;
	}
}

/// @brief METODO Q SALVA O USER
void Server::USER(void) {
	if (this->client->authUser == true) {
		this->resClient(":" + this->getIp() + " " + ERR_ALREADYREGISTRED + " " + this->client->nick + " :Comando não autorizado (já registrado)"); // Unauthorized command (already registered)
	} else if (this->argsCmd.size() < 5) {
		this->resClient(":" + this->getIp() + " " + ERR_NEEDMOREPARAMS + " " + this->client->nick + " USER :Parâmetros insuficientes"); // Not enough parameters
	} else {
		this->client->authUser = true;

		// AKI EU VERIFICO E DOU BOAS VINDAS COM MENSAGEM 001 002 E 003??
	}
}