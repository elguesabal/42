#include "header.h"

/// @brief METODO Q RESPONDE AO COMANDO "CAP"
void Server::CAP(void) {
	if (this->bufferStr == "CAP LS 302") {
		std::string res = ":" + this->getIp() + " CAP * LS\r\n";
		send(this->client->getFd(), res.c_str(), res.size(), 0);
	}
}

/// @brief METODO Q LIDA COM A VALIDACAO DA SENHA
void Server::PASS(void) {
	if (this->client->auth == true) {
		std::string res = ":" + this->getIp() + " " + ERR_ALREADYREGISTRED + " " + this->client->nick + " :Comando não autorizado (já registrado)\r\n"; // Unauthorized command (already registered)
		send(this->client->getFd(), res.c_str(), res.size(), 0);
	} else if (this->bufferStr.substr(5) != this->password) {
		std::string res = ":" + this->getIp() + " " + ERR_PASSWDMISMATCH + " * :Senha incorreta\r\n"; // Password incorrect
		send(this->client->getFd(), res.c_str(), res.size(), 0);
		this->deleteClient();
		this->bufferStrs.clear(); // INPEDE Q OS COMANDO NICK E USER SEJAM AXECUTADOS MESMO COM O CLIENTE FECHADO
	} else {
		this->client->auth = true;
	}
}

/// @brief METODO RESPONSAVEL POR VERIFICAR SE O NICK ESTA DISPONIVEL SALVAR
void Server::NICK(void) {
	std::string nick = this->bufferStr.substr(5);

	if (nick == "") {
		// std::cout << "nao veio o nick" << std::endl;
		std::string res = ":" + this->getIp() + " " + ERR_NONICKNAMEGIVEN + " * :Nenhum apelido fornecido\r\n"; // No nickname given
		send(this->client->getFd(), res.c_str(), res.size(), 0);
	} else if (this->nickInvalid(nick)) {
		// std::cout << "nick proibido" << std::endl;
		std::string res = ":" + this->getIp() + " " + ERR_ERRONEUSNICKNAME " " + (this->client->nick.empty() ? "*" : this->client->nick) + " " + nick + " :Apelido inválido\r\n"; // Erroneous nickname
		send(this->client->getFd(), res.c_str(), res.size(), 0);
	} else if (this->nickInUse(nick)) {
		// std::cout << "nick em uso" << std::endl;
		std::string res = ":" + this->getIp() + " " + ERR_NICKNAMEINUSE + " * " + nick + " :O apelido já está em uso\r\n"; // Nickname is already in use
		send(this->client->getFd(), res.c_str(), res.size(), 0);
// this->client->nick = nick; // SAPOHA DE HEXCHAT BUGA QUANDO ELA MANDA O SEGUNDO NICK PQ ELA NAO LEVA APARENTA ESPERAR Q EU MENCIONE O NICK Q EU RECUSEI
	} else {
		// std::cout << "nick livre" << std::endl;
		std::string res = ":" + (this->client->nick.empty() ? "*" : this->client->nick) + " NICK :" + nick + "\r\n";
		this->nickClient[nick] = this->client;
		this->client->nick = nick;
std::cout << res;
		send(this->client->getFd(), res.c_str(), res.size(), 0);
	}
}

/// @brief METODO Q SALVA O USER
void Server::USER(void) {
	// std::cout << "caiu no user" << std::endl;
}