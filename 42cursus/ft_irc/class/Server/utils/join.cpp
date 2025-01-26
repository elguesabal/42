#include "header.h"

/// @brief CRIA O CANAL ADICIONANDO O CRIADOR E DANDO O STATUS DE OPERADOR A ELE
/// @brief ABAIXO UMA LISTA DE RESPOSTA ENVIADAS
/// @brief RESPOSTA CONFIRMANDO A ENTRADA NO CANAL -> ":<apelido>!<usuario>@<host> JOIN :<canal>"
/// @brief RESPOSTA COM O TOPICO -> ":<servidor> 331 <apelido> <canal> :Nenhum tópico está definido" OU ":<servidor> 332 <apelido> <canal> :<tópico>"
/// @brief RESPOSTA COM A LISTA DE USUARIOS -> ":<servidor> 353 <apelido> = #meucanal :@<apelido>"
/// @brief RESPOSTA DE FIM DE LISTA -> ":<servidor> 366 <apelido> #meucanal :Fim da lista de nomes"
/// @brief INFORMA Q O MODO TOPICO ESTA ATIVO COM A RESPOSTA ":<servidor> MODE <canal> <modo>"
/// @param channel NOME DO CANAL Q SERA CRIADO
void Server::creatChannel(std::string &channel) {
	this->channels[channel] = new Channel(this->client);

// :<apelido>!<usuario>@<host> JOIN :<canal>
	this->resClient(":" + this->client->nick + "!" + this->client->user + "@" + this->client->getIp() + " JOIN :" + channel);

// :<servidor> 331 <apelido> <canal> :No topic is set
// :<servidor> 332 <apelido> <canal> :<tópico do canal>
	this->resClient(":" + this->getIp() + " " + RPL_NOTOPIC + " " + this->client->nick + " " + channel + " :Nenhum tópico está definido"); // No topic is set

// :<servidor> 353 <apelido> = #meucanal :@<apelido>
	this->resClient(":" + this->getIp() + " " + RPL_NAMREPLY + " " + this->client->nick + " = " + channel + " :@" + this->client->nick);

// :<servidor> 366 <apelido> #meucanal :End of NAMES list.
	this->resClient(":" + this->getIp() + " " + RPL_ENDOFNAMES + " " + this->client->nick + " " + channel + " :Fim da lista de nomes"); // End of NAMES list

// :<servidor> MODE <canal> <modos>
	this->resClient(":" + this->getIp() + " MODE " + channel + " +t");
}

/// @brief ADICIONA O CLIENTE COMO MEMBRO A UM CANAL JA EXISTE
/// @brief ABAIXO UMA LISTA DE RESPOSTA ENVIADAS
/// @brief RESPOSTA CONFIRMANDO A ENTRADA NO CANAL -> ":<apelido>!<usuario>@<host> JOIN <canal>"
/// @brief ENVIADO RESPOSTA AOS OUTROS MEMBROS DO CANAL -> ":<apelido>!<usuario>@<host> JOIN <canal>"
/// @brief RESPOSTA COM O TOPICO -> ":<servidor> 331 <apelido> <canal> :Nenhum tópico está definido" OU ":<servidor> 332 <apelido> <canal> :<tópico>"
/// @brief RESPOSTA COM A LISTA DE USUARIOS -> ":<servidor> 353 <apelido> = <canal> :[prefixos]<apelido1> [prefixos]<apelido2> ..."
/// @brief RESPOSTA DE FIM DE LISTA -> ":<servidor> 366 <apelido> #meucanal :Fim da lista de nomes"
/// @param channel NOME DO CANAL Q SERA ADICIONADO O NOVO MEMBRO
void Server::joinChannel(std::string &channel) {
	this->channels[channel]->newMember(this->client);

// :<apelido>!<usuario>@<host> JOIN <canal>
	this->sendChannel(":" + this->client->nick + "!" + this->client->user + "@" + this->getIp() + " JOIN " + channel, this->channels[channel]);

// :<apelido>!<usuario>@<host> JOIN <canal>
	this->resClient(":" + this->client->nick + "!" + this->client->user + "@" + this->getIp() + " JOIN " + channel);

// :<servidor> 332 <apelido> <canal> :<tópico do canal>
	this->resClient(":" + this->getIp() + " " + (this->channels[channel]->topic == "" ? RPL_NOTOPIC : RPL_TOPIC) + " " + this->client->nick + " " + channel + " :" + (this->channels[channel]->topic == "" ? "Nenhum tópico está definido" : this->channels[channel]->topic)); // No topic is set

// :<servidor> 353 <apelido> = <canal> :[prefixos]<apelido1> [prefixos]<apelido2> ...
	std::string clients;
	for (unsigned int i = 0; i < this->channels[channel]->clients.size(); i++) {
		clients = "";
		for (unsigned int j = 0; j < 10 && i < this->channels[channel]->clients.size(); j++) {
			clients += (this->channels[channel]->clients[i]->o == true ? "@" : "");
			clients += this->channels[channel]->clients[i]->client->nick + " ";
			i++;
		}
		i--;
		this->resClient(":" + this->getIp() + " " + RPL_NAMREPLY + " " + this->client->nick + " = " + channel + " :" + clients);
	}

// :<servidor> 366 <apelido> <canal> :End of NAMES list
	this->resClient(":" + this->getIp() + " " + RPL_ENDOFNAMES + " " + this->client->nick + " " + channel + " :Fim da lista de nomes"); // End of NAMES list
}