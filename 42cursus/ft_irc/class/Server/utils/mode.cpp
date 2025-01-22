#include "header.h"

/// @brief ENVIA UMA MENSAGEM PARA TODOS DO CANAL (INCLUINDO O OPERADOR Q PROMOVEU O MEMBRO) INFORMANDO Q ALGUEM VIROU OPERADOR ":<apelido>!<usuario>@<host> MODE <canal> +o <usuario>"
/// @brief SE O NICK FOR UMA STRING VAZIA RESPONDE COM ":<servidor> 461 A PRIVMSG :Parâmetros insuficientes"
/// @brief CASO O NICK NAO ESTEJA NO CANAL RESPONDE COM ":<servidor> 441 <operador> <usuario> <canal> :Este nick não está no canal"
/// @brief CASO A O NICK ESTEJA DENTRO DO CANAL MANDA UMA MENSAGEM PARA TODOS OS MEMBROS DO CANAL ":<apelido>!<usuario>@<host> MODE #canal +o usuario"
/// @param channel NOME DO CANAL Q VAI ACONTECER A PROMOCAO DE MEMBRO
/// @param mode BOOLEAN Q REPRESENTA AS BANDEIRAS MODE + (true) E - (false)
/// @param nick NICK DO USUARIO Q VAI GANHAR OU PEDER O STATUS DE OPERADOR
void Server::o(std::string &channel, bool mode, std::string nick) {
	if (nick == "") {
// // :<servidor> 461 <apelido> MODE :Not enough parameters
		this->resClient(":" + this->getIp() + " " + ERR_NEEDMOREPARAMS + this->client->nick + " MODE :Parâmetros insuficientes"); // Not enough parameters
	} else if (this->channels[channel]->nickClient.count(nick) == 0) {
// :<servidor> 441 <operador> <usuario> <canal> :They aren't on that channel
		this->resClient(":" + this->getIp() + " " + ERR_USERNOTINCHANNEL + " " + this->client->nick + " " + nick + " " + channel + " :Este nick não está no canal"); // They aren't on that channel
		return ;
	}

	this->channels[channel]->nickClient[nick]->o = mode;
// :<apelido>!<usuario>@<host> MODE #canal +o usuario
	this->resChannel(":" + this->client->nick + "!" + this->client->user + "@" + this->client->getIp() + " MODE " + channel + " " + (mode == true ? "+" : "-") + "o " + nick, this->channels[channel]);
}


/// @brief 
/// @param channel NOME DO CANAL Q VAI SER MODIFICADO
void Server::k(std::string &channel, bool mode, std::string password) {
	if (mode == true && password == "") {
											// AKI EU TENHO Q EXIGIR A SENHA
		// this->resClient();
		return ;
	}

	this->channels[channel]->k = mode;				// PAREI AKI DEFININDO O MODE DA SENHA
	if (mode == true) {
		this->channels[channel]->password = password;
	}
	// this->resChannel();
}


// else if (this->argsCmd.size() < 4) {
// // :<servidor> 461 <apelido> MODE :Not enough parameters
// 		this->resClient(":" + host + " " + ERR_NEEDMOREPARAMS + nick + " MODE :Parâmetros insuficientes"); // Not enough parameters
// 	} 