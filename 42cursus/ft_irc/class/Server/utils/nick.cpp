#include "header.h"

/// @brief VERIFICA SE HA ALGUM CARACTER PROIBIDO NO NICK
/// @param nick NICK A SER ANALIZADO
/// @return RETORNA TRUE CASO HA ALGUM NICK PROIBIDO E FALSE CASO NAO
bool Server::nickInvalid(std::string &nick) {
	std::string charInvalid = " \r\n;@!*,";

	for (unsigned short i = 0; i < charInvalid.size(); i++) {
		if (nick.find(charInvalid[i]) != std::string::npos) {
			return (true);
		}
	}

	if (this->serverCommands.find(nick) != this->serverCommands.end()) {
		return (true);
	}

	return (false);
}

/// @brief VERIFICA SE O NICK ESTA EM USO
/// @param nick NICK A SER ANALIZADO
/// @return RETORNA TRUE CASO O NICK ESTEJA EM USO E FALSE CASO NAO (RETORNA FALSE CASO O PROPRIO USUARIO ESTEJA REDEFININDO PARA SEU PROPRIO NICK)
bool Server::nickInUse(std::string &nick) {
	// if (this->nickClient.find(nick) != this->nickClient.end()) {
	// 	return (true);
	// }

	std::string nickUpper = Server::toUpper(nick);
	for (unsigned int i = 0; i < this->clients.size(); i++) {
		if (nickUpper == Server::toUpper(this->clients[i]->nick) && this->client != this->clients[i]) {
			return (true); // DEVO IGNORAR O CLIENTE CASO ELE TENTE ALTERAR O NICK PARA O PROPRIO NICK??
		}
	}

	return (false);
}