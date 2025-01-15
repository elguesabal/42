#include "header.h"

/// @brief CRIA O CANAL ADICIONANDO O CRIADOR E DANDO O STATUS DE OPERADOR A ELE
/// @brief ABAIXO UMA LISTA DE RESPOSTA ENVIADAS
/// @brief RESPOSTA CONFIRMANDO A ENTRADA NO CANAL -> ":<apelido>!<usuario>@<host> JOIN :<canal>"
/// @brief RESPOSTA COM O TOPICO -> ":<servidor> 331 <apelido> <canal> :Nenhum tópico está definido" OU ":<servidor> 332 <apelido> <canal> :<tópico>"
/// @brief RESPOSTA COM A LISTA DE USUARIOS -> ":<servidor> 353 <apelido> = #meucanal :@<apelido>"
/// @brief RESPOSTA DE FIM DE LISTA -> ":<servidor> 366 <apelido> #meucanal :Fim da lista de nomes"
void Server::creatChannel(void) {
	this->channels[this->argsCmd[1]] = new Channel(this->argsCmd[1], this->client);

// :<apelido>!<usuario>@<host> JOIN :<canal>
	this->resClient(":" + this->client->nick + "!" + this->client->user + "@" + this->client->getIp() + " JOIN :" + this->argsCmd[1]);

// :<servidor> 331 <apelido> <canal> :No topic is set
// :<servidor> 332 <apelido> <canal> :<tópico do canal ou mensagem vazia>
	this->resClient(":" + this->getIp() + " " + RPL_NOTOPIC + " " + this->client->nick + " " + this->argsCmd[1] + " :Nenhum tópico está definido"); // No topic is set

// :<servidor> 353 <apelido> = #meucanal :@<apelido>
	this->resClient(":" + this->getIp() + " " + RPL_NAMREPLY + " " + this->client->nick + " = " + this->argsCmd[1] + " :@" + this->client->nick);

// :<servidor> 366 <apelido> #meucanal :End of NAMES list.
	this->resClient(":" + this->getIp() + " " + RPL_ENDOFNAMES + " " + this->client->nick + " " + this->argsCmd[1] + " :Fim da lista de nomes"); // End of NAMES list
}

/// @brief ADICIONA O CLIENTE COMO MEMBRO A UM CANAL JA EXISTE
/// @brief ABAIXO UMA LISTA DE RESPOSTA ENVIADAS
/// @brief RESPOSTA CONFIRMANDO A ENTRADA NO CANAL -> ":<apelido>!<usuario>@<host> JOIN <canal>"
/// @brief ENVIADO RESPOSTA AOS OUTROS MEMBROS DO CANAL -> ":<apelido>!<usuario>@<host> JOIN <canal>"
/// @brief RESPOSTA COM O TOPICO -> ":<servidor> 331 <apelido> <canal> :Nenhum tópico está definido" OU ":<servidor> 332 <apelido> <canal> :<tópico>"
/// @brief RESPOSTA COM A LISTA DE USUARIOS -> ":<servidor> 353 <apelido> = <canal> :[prefixos]<apelido1> [prefixos]<apelido2> ..."
/// @brief RESPOSTA DE FIM DE LISTA -> ":<servidor> 366 <apelido> #meucanal :Fim da lista de nomes"
void Server::joinChannel(void) {
	this->channels[this->argsCmd[1]]->addClient(this->client);

// :<apelido>!<usuario>@<host> JOIN <canal>
	this->sendChannel(":" + this->client->nick + "!" + this->client->user + "@" + this->getIp() + " JOIN " + this->argsCmd[1], this->channels[this->argsCmd[1]]);

// :<apelido>!<usuario>@<host> JOIN <canal>
	this->resClient(":" + this->client->nick + "!" + this->client->user + "@" + this->getIp() + " JOIN " + this->argsCmd[1]);

// :<servidor> 332 <apelido> <canal> :<tópico do canal>
	this->resClient(":" + this->getIp() + " " + (this->channels[this->argsCmd[1]]->topic == "" ? RPL_NOTOPIC : RPL_TOPIC) + " " + this->client->nick + " " + this->argsCmd[1] + " :" + (this->channels[this->argsCmd[1]]->topic == "" ? "Nenhum tópico está definido" : this->channels[this->argsCmd[1]]->topic)); // No topic is set

// :<servidor> 353 <apelido> = <canal> :[prefixos]<apelido1> [prefixos]<apelido2> ...
	std::string clients;
	for (unsigned int i = 0; i < this->channels[this->argsCmd[1]]->clients.size(); i++) {
		clients = "";
		for (unsigned int j = 0; j < 10 && i < this->channels[this->argsCmd[1]]->clients.size(); j++) {
			clients += (this->channels[this->argsCmd[1]]->clients[i].o == true ? "@" : "");
			clients += this->channels[this->argsCmd[1]]->clients[i].client->nick + " ";
			i++;
		}
		i--;
		this->resClient(":" + this->getIp() + " " + RPL_NAMREPLY + " " + this->client->nick + " = " + this->argsCmd[1] + " :" + clients);
	}

// :<servidor> 366 <apelido> <canal> :End of NAMES list
	this->resClient(":" + this->getIp() + " " + RPL_ENDOFNAMES + " " + this->client->nick + " " + this->argsCmd[1] + " :Fim da lista de nomes"); // End of NAMES list
}