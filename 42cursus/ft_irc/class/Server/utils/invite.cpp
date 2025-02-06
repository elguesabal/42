#include "header.h"

/// @brief ENVIA UMA MENSAGEM PARA O CONVIDADOR ":<servidor> 341 <apelido_convidador> <apelido_convidado> <canal>"
/// @brief ENVIA UMA MENSAGEM PARA O CONVIDADO ":<apelido_convidador>!<user>@<host> <comando> <apelido_convidado> :<canal>"
/// @brief ADICIONA O CONVITE NA LISTA DE CONVITE DO CONVIDADO
/// @param client CLIENTE A SER CONVIDADO
/// @param channel CANAL O CLIENTE IRA SER CONVIDADO
void Server::toInvite(std::string &client, std::string &channel) {
	this->resClient(":" + this->getIp() + " " + RPL_INVITING + " " + this->client->nick + " " + client + " " + channel);
	this->sendClient(":" + this->client->nick + "!" + this->client->user + "@" + this->client->getIp() + " INVITE " + client + " :" + channel, this->nickClient[client]);
	this->nickClient[client]->invite.push_back(channel);
}