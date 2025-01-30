#include "header.h"

/// @brief VERIFICA SE O NICK ESTA EM USO
/// @param nick NICK A SER ANALIZADO
/// @return RETORNA TRUE CASO O NICK ESTEJA EM USO E FALSE CASO NAO
bool Server::nickInUse(std::string &nick) {
	std::string nickUpper = Server::toUpper(nick);

	for (unsigned int i = 0; i < this->clients.size(); i++) {
		if (nickUpper == Server::toUpper(this->clients[i]->nick)) {
			return (true);
		}
	}
	return (false);
}

/// @brief REPONDE COM ":<servidor> 464 <nick> :Senha necessária" E FECHA A CONEXAO
void Server::unauthPass(void) {
	this->resClient(":" + this->getIp() + " " + ERR_PASSWDMISMATCH + " * :Senha necessária"); // Password required
	this->deleteClient();
}

/// @brief TROCA DE NICK COM USUARIO JA AUTENTICADO RESPONDE COM ":<antigo nick> NICK :<novo nick>"
/// @brief TBM NOTIFICA OS CANAIS COM A MENSGEM ":<antigo nick>!<usuario>@<host> NICK :<novo nick>"
/// @brief REMOVE A ANTIGA CHAVE DE "nickClient" E CHAMA A FUNCAO "this->client->setNick()"
void Server::swapNick(void) {
	this->resClient(":" + this->client->nick + " NICK :" + this->argsCmd[1]);
	for (unsigned int i = 0; i < this->client->channels.size(); i++) {
		this->resChannel(":" + this->client->nick + "!" + this->client->user + "@" + this->client->getIp() + " NICK :" + this->argsCmd[1], this->client->channels[i]);
	}
	this->nickClient.erase(this->client->nick);
	this->nickClient[this->argsCmd[1]] = this->client;
	this->client->setNick(this->argsCmd[1]);
}

/// @brief ATRIBUI O NICK A UM USUARIO Q NUNCA TEVE NICK (NAO AH RESPOSTA IMEDIATA APENAS AGUARDA RESPOSTA DE BOAS VINDAS DENTRO DA FUNCAO "this->authentication();")
void Server::assignNick(void) {
	this->nickClient[this->argsCmd[1]] = this->client;
	this->client->nick = this->argsCmd[1];
	this->client->authNick = true;
}