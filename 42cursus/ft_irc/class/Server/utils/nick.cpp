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