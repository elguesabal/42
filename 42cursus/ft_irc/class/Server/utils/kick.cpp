#include "header.h"

/// @brief REMOVE O CLIENTE DO CANAL E NOTIFICA TODOS OS MEMBROS COM ":<kicker_apelido>!<user>@<host> KICK <canal> <apelido> :<mensagem>"
/// @param channel CANAL Q O CLIENTE SERA KICKADO
/// @param client CLIENTE A SER KICKADO DO CANAL
/// @param message MENSAGEM A SER ENCAMINHADA PARA O CANAL
void Server::removeClient(std::string &channel, std::string &client, std::string &message) {
// :<kicker_apelido>!<user>@<host> KICK <canal> <apelido> :<mensagem>
	this->resChannel(":" + this->client->nick + "!" + this->client->user + "@" + this->client->getIp() + " KICK " + channel + " " + client + " :" + message, this->channels[channel]);

// CLIENTE
// std::map<std::string, Channel *> channels;
	// this->client->channels.erase(channel);
	this->nickClient[client]->channels.erase(channel);

// CANAL
// std::map<std::string, ClientChanell *> nickClient;
	delete this->channels[channel]->clients[client];
	this->channels[channel]->clients.erase(client);

// SERVER
// std::map<std::string, Channel *> channels;
	if (this->channels[channel]->size() == 0) {
		delete this->channels[channel];
		this->channels.erase(channel);
	}
}