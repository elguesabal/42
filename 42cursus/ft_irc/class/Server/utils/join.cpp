#include "header.h"

/// @brief 
void Server::creatChannel(void) {
std::cout << "canal criado" << std::endl;
	this->channels[this->argsCmd[1]] = new Channel(this->argsCmd[1], this->client);

// :<apelido>!<usuario>@<host> JOIN :<canal>
	this->resClient(":" + this->client->nick + "!" + this->client->user + "@" + this->client->getIp() + " JOIN :" + this->argsCmd[1]);

// :<servidor> 331 <apelido> <canal> :No topic is set
	// this->resClient(":" + this->getIp() + " " + (this->channels[this->argsCmd[1]]->topic == "" ? RPL_NOTOPIC : RPL_TOPIC) + " " + this->client->nick + " " + this->argsCmd[1] + " :" + (this->channels[this->argsCmd[1]]->topic == "" ? "Nenhum tópico está definido" : this->channels[this->argsCmd[1]]->topic));
// :<servidor> 332 <apelido> <canal> :<tópico do canal ou mensagem vazia>
	this->resClient(":" + this->getIp() + " " + RPL_NOTOPIC + " " + this->client->nick + " " + this->argsCmd[1] + " :Nenhum tópico está definido");

// :<servidor> 353 <apelido> = #meucanal :@<apelido>
	this->resClient(":" + this->getIp() + " " + RPL_NAMREPLY + " " + this->client->nick + " = " + this->argsCmd[1] + " :@" + this->client->nick);

// :<servidor> 366 <apelido> #meucanal :End of /NAMES list.
	this->resClient(":" + this->getIp() + " " + RPL_ENDOFNAMES + " " + this->client->nick + " " + this->argsCmd[1] + " :Fim da lista de nomes");
}



/// @brief 
void Server::joinChannel(void) {
std::cout << "entrando no canal" << std::endl;

	this->channels[this->argsCmd[1]]->addClient(this->client); // PAREI AKI ADICIONANDO NOVOS MEMBROS AO CANAL (AINDA NAO TERMINEI O COMANDO JOIN)

// std::cout << "todos os clientes: " << std::endl;
// for (unsigned int i = 0; i < this->channels[this->argsCmd[1]]->clients.size(); i++) { // /join #teste
// 	std::cout << this->channels[this->argsCmd[1]]->clients[i].client->nick << std::endl;
// }

			// TESTAR AKI PQ TAVA DANDO ESSE ERRO AO UM NOVO MEBRO ENTRAR NO MESMO CANAL
==5874== Conditional jump or move depends on uninitialised value(s)
==5874==    at 0x1160F3: Server::JOIN() (in /home/jose/programacao/42/42cursus/ft_irc/ircserv)
==5874==    by 0x10CEBA: Server::newBuffer() (in /home/jose/programacao/42/42cursus/ft_irc/ircserv)
==5874==    by 0x10CB18: Server::listener() (in /home/jose/programacao/42/42cursus/ft_irc/ircserv)
==5874==    by 0x10BD2D: main (in /home/jose/programacao/42/42cursus/ft_irc/ircserv)
==5874==
}