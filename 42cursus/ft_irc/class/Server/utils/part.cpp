#include "header.h"

/// @brief INFORMA AO CANAL Q O USUARIO SAIU COM A MENSAGEM ":<apelido>!<usuario>@<host> PART <canal> :<mensagem>"
/// @brief DESASSOCIA A VARIAVEL "std::vector<Channel *> channels;" DENTRO DA CLASSE "Client"
/// @brief DESASSOCIA A VARIAVEL "std::vector<ClientChanell *> clients;" DENTRO DA CLASSE "Channel"
/// @brief DESASSOCIA A VARIAVEL "std::map<std::string, ClientChanell *> nickClient;" DENTRO DA CLASSE "Channel"
/// @brief CASO NAO ESXISTA MAIS CLIENTE DENTRO DO CANAL LIBERA A MEMORIA ALOCADA PARA O CANAL E DESASSOCIA A VARIAVEL "std::map<std::string, Channel *> channels;" DENTRO DA CLASSE "Server"
/// @param channel NOME DO CANAL Q O USUARIO QUER SAIR
void Server::exitChannel(std::string &channel) {
// :<apelido>!<usuario>@<host> PART <canal> :<mensagem>
	this->resChannel(":" + this->client->nick + "!" + this->client->user + "@" + this->client->getIp() + " PART " + channel + (this->argsCmd.size() > 2 ? " :" + this->argsCmd[2] : ""), this->channels[channel]);


// CLIENTE
// std::vector<Channel *> channels;
	for (unsigned int i = 0; i < this->client->channels.size(); i++) {
		if (this->client->channels[i] == this->channels[channel]) {
			this->client->channels.erase(this->client->channels.begin() + i);
			break ;
		}
	}


// CANAL
// std::vector<ClientChanell *> clients;
	for (unsigned int i = 0; i < this->channels[channel]->clients.size(); i++) {
		if (this->channels[channel]->clients[i]->client->nick == this->client->nick) {
			this->channels[channel]->clients.erase(this->channels[channel]->clients.begin() + i);
			break ;
		}
	}

// std::map<std::string, ClientChanell *> nickClient;
	this->channels[channel]->nickClient.erase(this->client->nick);


// SERVER
// std::map<std::string, Channel *> channels;
	if (this->channels[channel]->size() == 0) {
		delete this->channels[channel];
		this->channels.erase(channel);
	}
} // TESTAR UM POUCO MAIS ISSO AKI (OU NAO KKKKKK)