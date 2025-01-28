#include "header.h"

/// @brief ENVIA A INFORMACOES DE TODOS OS CANAIS
/// @brief ENVIA O CABECALHO ":<servidor> 321 <apelido> Channel :Users  Name" (CAIU EM DESUSO MAS DECIDI DEIXAR)
/// @brief ENVIA AS INFORMACOES DE CADA CANAL COM A MENSAGEM ":<servidor> 322 <apelido> <canal> <número de usuários> :<tópico do canal>"
/// @brief ENVIA A INFORMACAO Q A LISTA TERMINOU ":<servidor> 323 <apelido> :End of /LIST"
void Server::listChannels(void) {
	std::string host = this->getIp();
	std::string nick = this->client->nick;

// :<servidor> 321 <apelido> Channel :Users  Name
	this->resClient(":" + host + " " + RPL_LISTSTART + " " + nick + " Channel :Users  Name");

	for (std::map<std::string, Channel *>::iterator it = this->channels.begin(); it != this->channels.end(); ++it) {
// std::cout << "teste: '" << it->first << "'" << std::endl;
		if (it->second->i == false) {
			std::stringstream size;
			size << it->second->size();
// :<servidor> 322 <apelido> <canal> <número de usuários> :<tópico do canal>
			this->resClient(":" + host + " " + RPL_LIST + " " + nick + " " + it->first + " " + size.str() + " :" + it->second->topic);
		}
	}

// :<servidor> 323 <apelido> :End of /LIST
	this->resClient(":" + host + " " + RPL_LISTEND + " " + nick + " :End of /LIST");
}

/// @brief ENVIA A INFORMACOES DOS CANAIS ESPECIFICADOS
/// @brief ENVIA O CABECALHO ":<servidor> 321 <apelido> Channel :Users  Name" (CAIU EM DESUSO MAS DECIDI DEIXAR)
/// @brief ENVIA AS INFORMACOES DE CADA CANAL EXISTENTE COM A MENSAGEM ":<servidor> 322 <apelido> <canal> <número de usuários> :<tópico do canal>"
/// @brief ENVIA A INFORMACAO Q A LISTA TERMINOU ":<servidor> 323 <apelido> :End of /LIST"
void Server::searchChannels(std::vector<std::string> &channels) {
	std::string host = this->getIp();
	std::string nick = this->client->nick;

// :<servidor> 321 <apelido> Channel :Users  Name
	this->resClient(":" + host + " " + RPL_LISTSTART + " " + nick + " Channel :Users  Name");

	for (unsigned int i = 0; i < channels.size(); i++) {
		if (this->channels.count(channels[i]) == 1 && this->channels[channels[i]]->i == false) {
			std::stringstream size;
			size << this->channels[channels[i]]->size();
// :<servidor> 322 <apelido> <canal> <número de usuários> :<tópico do canal>
			this->resClient(":" + host + " " + RPL_LIST + " " + nick + " " + channels[i] + " " + size.str() + " :" + this->channels[channels[i]]->topic);
		}
	}

// :<servidor> 323 <apelido> :End of /LIST
	this->resClient(":" + host + " " + RPL_LISTEND + " " + nick + " :End of /LIST");
}