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
void Server::swapNick(void) {
	this->resClient(":" + this->client->nick + " NICK :" + this->argsCmd[1]);
	this->nickClient.erase(this->client->nick);

// TENHO Q TROCAR NOS CANAIS TBM
	// this->channels; // VOU CRIAR UM vector DENTRO DO CLIENTE Q VAI GUARDAR TODOS OS CANAIS

	this->nickClient[this->argsCmd[1]] = this->client;
	this->client->nick = this->argsCmd[1];
}

/// @brief ATRIBUI O NICK A UM USUARIO Q NUNCA TEVE NICK (NAO AH RESPOSTA IMEDIATA APENAS AGUARDA RESPOSTA DE BOAS VINDAS DENTRO DA FUNCAO "this->authentication();")
void Server::assignNick(void) {
	this->nickClient[this->argsCmd[1]] = this->client;
	this->client->nick = this->argsCmd[1];
	this->client->authNick = true;
}