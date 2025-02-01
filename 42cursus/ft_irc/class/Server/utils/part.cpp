#include "header.h"

// /// @brief INFORMA AO CANAL Q O USUARIO SAIU COM A MENSAGEM ":<apelido>!<usuario>@<host> PART <canal> :<mensagem>"
// /// @brief DESASSOCIA A VARIAVEL "std::map<std::string, Channel *> channels;" DENTRO DA CLASSE "Client"
// /// @brief DESASSOCIA A VARIAVEL "std::map<std::string, ClientChanell *> nickClient;" DENTRO DA CLASSE "Channel"
// /// @brief CASO NAO ESXISTA MAIS CLIENTE DENTRO DO CANAL LIBERA A MEMORIA ALOCADA PARA O CANAL E DESASSOCIA A VARIAVEL "std::map<std::string, Channel *> channels;" DENTRO DA CLASSE "Server"
// /// @param channel NOME DO CANAL Q O USUARIO QUER SAIR
// void Server::exitChannel(std::string &channel) {
// 	this->resChannel(":" + this->client->nick + "!" + this->client->user + "@" + this->client->getIp() + " PART " + channel + (this->argsCmd.size() > 2 ? " :" + this->argsCmd[2] : ""), this->channels[channel]);

// // CLIENTE
// // std::map<std::string, Channel *> channels;
// 	this->client->channels.erase(channel);


// // CANAL
// // std::map<std::string, ClientChanell *> nickClient;
// 	delete this->channels[channel]->clients[this->client->nick];
// 	this->channels[channel]->clients.erase(this->client->nick);


// // SERVER
// // std::map<std::string, Channel *> channels;
// 	if (this->channels[channel]->size() == 0) {
// 		delete this->channels[channel];
// 		this->channels.erase(channel);
// 	}
// }