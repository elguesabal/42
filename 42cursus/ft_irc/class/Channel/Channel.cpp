#include "header.h"

/// @brief CONSTRUTOR DO STRUCT ClientChannel
/// @param client CLIENTE Q VAI CRIAR O CANAL
Channel::ClientChanell::ClientChanell(Client *client) : client(client), o(false) {

}

/// @brief CONSTRUTOR DA CLASSE Channel
/// @param client CLIENTE Q VAI CRIAR O CANAL
Channel::Channel(Client *client) : i(false), t(true), k(false), l(false), topic("") {
	this->newMember(client);
	this->clients[0]->o = true;
}

/// @brief DESTRUTOR DA CLASSE
Channel::~Channel(void) {
	// AKI EU TENHO Q USAR delete NO std::vector<ClientChanell *> clients
}

/// @brief ADICIONA UM CLIENTE A LISTA DE MEMBROS DO CANAL
/// @param client CLIENTE A SER ADICIONADO
void Channel::newMember(Client *client) {
	try {
		ClientChanell *newClient = new ClientChanell(client);

		this->clients.push_back(newClient);
		this->nickClient[client->nick] = newClient;
		client->channels.push_back(this);
	} catch (const std::exception &error) {
		throw ;
	}
}