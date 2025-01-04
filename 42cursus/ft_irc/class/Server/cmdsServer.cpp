#include "header.h"

/// @brief COMANDO DE NEGOCIACAO DE CAPACIDADES "CAP LS 302" RESPONDE COM ":<servidor> CAP <nick> LS :"
/// @brief "CAP END" NAO RESPONDE (FIM DA NEGOCIACAO DE CAPACIDADES)
void Server::CAP(void) {
	if (this->cmd == "CAP LS 302") {
		this->resClient(":" + this->getIp() + " CAP * LS");
	} else if (this->cmd == "CAP END") {

	}
}

/// @brief SE O COMANDO "NICK" FOR RECEBIDO SEM O COMANDO "PASS" ANTERIORMENTE REPONDE COM ":<servidor> 464 <nick> :Senha necessária" E FECHA A CONEXAO
/// @brief COMANDO "NICK" ENVIADO SEM NENHUM ARGUMENTO RESPONDE COM ":<servidor> 431 <nick> :Nenhum nick fornecido"
/// @brief CASO O NICK CONTENHA UM CARACTER PROIBIDO RESPONDE COM ":<servidor> 431 <nick> :Nick inválido"
/// @brief CASO O NICK JA ESTE EM USO RESPONDE COM ":<servidor> 433 <nick> :O nick já está em uso"
/// @brief TROCA DE NICK COM USUARIO JA AUTENTICADO RESPONDE COM ":<antigoNick> NICK :<novoNick>"
/// @brief INSERCAO DE NICK EM CLIENTE NAO AUTENTICADO NAO TEM RESPOSTA (AGUARDA RESPOSTA DE BOASS VINDAS)
void Server::NICK(void) {
	if (this->client->authPass == false) {
		this->resClient(":" + this->getIp() + " " + ERR_PASSWDMISMATCH + " * :Senha necessária"); // Password required
		this->deleteClient();
	} else if (this->argsCmd.size() < 2) {
		this->resClient(":" + this->getIp() + " " + ERR_NONICKNAMEGIVEN + " * :Nenhum nick fornecido"); // No nickname 
	} else if (this->nickInvalid(this->argsCmd[1])) {
		this->resClient(":" + this->getIp() + " " + ERR_ERRONEUSNICKNAME " " + this->client->nick + " " + this->argsCmd[1] + " :Nick inválido"); // Erroneous nickname
	} else if (this->nickInUse(this->argsCmd[1])) { // DEVO IGNORAR O CLIENTE CASO ELE TENTE ALTERAR O NICK PARA O PROPRIO NICK??
		// std::cout << "nick em uso" << std::endl;
		this->resClient(":" + this->getIp() + " " + ERR_NICKNAMEINUSE + " " + this->client->nick + " " + this->argsCmd[1] + " :O nick já está em uso"); // Nickname is already in use
	} else if (this->client->authNick == true) {
		this->resClient(":" + this->client->nick + " NICK :" + this->argsCmd[1]); // ACHO Q ERA PRA TER O PREFIXO ":<servidor>"?? ACHO Q ESSA MENSAGEM E UMA EXCECAO
		this->nickClient.erase(this->client->nick);
		this->nickClient[this->argsCmd[1]] = this->client;
		this->client->nick = this->argsCmd[1];
	} else {
		this->nickClient[this->argsCmd[1]] = this->client;
		this->client->nick = this->argsCmd[1];
		this->client->authNick = true;
	}

	this->authentication();
}

/// @brief CLIENTE TENTANDO AUTENTICAR A SENHA NOVAMENTE RESPONDE COM ":<servidor> 462 <nick> :Comando não autorizado (já registrado)"
/// @brief CLIENTE MANDOU APENAS O COMANDO "PASS" SEM A SENHA RESPONDE COM ":<servidor> 464 <nick> :Senha necessária" E FECHA A CONEXAO
/// @brief SENHA ERRADA RESPONDE COM ":<servidor> 464 <nick> :Senha incorreta" E FECHA A CONEXAO
/// @brief VALIDA A SENHA DO CLIENTE E NAO RESPONDE
void Server::PASS(void) {
	if (this->client->authPass == true) {
		this->resClient(":" + this->getIp() + " " + ERR_ALREADYREGISTRED + " " + this->client->nick + " :Comando não autorizado (já registrado)"); // Unauthorized command (already registered)
	} else if (this->argsCmd.size() < 2) {
		this->resClient(":" + this->getIp() + " " + ERR_PASSWDMISMATCH + " * :Senha necessária"); // Password required
		this->deleteClient();
	} else if (this->argsCmd[1] != this->password) {
		this->resClient(":" + this->getIp() + " " + ERR_PASSWDMISMATCH + " * :Senha incorreta"); // Password incorrect
		this->deleteClient();
	} else {
		this->client->authPass = true;
	}
}

/// @brief PING COM MENOS DE 2 ARGUMENTOS E RESPONDIDO COM ":<servidor> 409 <cliente> :Nenhuma origem especificada"
/// @brief CASO O PING SEJA BEM SUCEDIDO RESPONDE COM "PONG <token>"
void Server::PING(void) {
	if (this->client->auth == false) {

	} else if (this->argsCmd.size() < 2) {
		this->resClient(":" + this->getIp() + " " + ERR_NOORIGIN + " " + this->client->nick + " :Nenhuma origem especificada"); // No origin specified
	} else {
		this->resClient(":" + this->getIp() + " PONG ft_irc :" + this->argsCmd[1]);
	}
}

/// @brief 
void Server::QUIT(void) {
	this->deleteClient();
	// O SERVIDOR DEVE MANDAR MENSAGEM PARA TODOS OS CANAIS NOTIFICANDO A SAIDA
}

/// @brief O COMANDO "USER" SO DEVE SER RECEBIDO UMA VEZ NA AUTENTICACAO E QUALQUER OUTRA TENTATIVA DESTE COMANDO SERA RESPONDIDO COM ":<servidor> 462 <nick> :Comando não autorizado (já registrado)"
/// @brief SE ESTIVER FALTANDO PARAMETROS RESPONDE COM ":<servidor> 461 <nick> USER :Parâmetros insuficientes"
/// @brief CASO NAO TENHA SIDO RESPONDIDO COM NENHUMA DAS 2 OPCOES ACIMA APENAS SALVAR O user ATRIBUI true PARA authuser
/// @brief INDEPENDENTE DAS OUTRAS OPCOES ACIMA SE AS 3 VARIAVEIS authPass, authNick E authUser FOREM true RESPONDE COM AS MENSAGENS 001, 002 E 003
void Server::USER(void) {
	if (this->client->authUser == true) {
		this->resClient(":" + this->getIp() + " " + ERR_ALREADYREGISTRED + " " + this->client->nick + " :Comando não autorizado (já registrado)"); // Unauthorized command (already registered)
	} else if (this->argsCmd.size() < 5) {
		this->resClient(":" + this->getIp() + " " + ERR_NEEDMOREPARAMS + " " + this->client->nick + " USER :Parâmetros insuficientes"); // Not enough parameters
	} else {
		this->client->user = this->argsCmd[1];
		this->client->authUser = true;
	}

	this->authentication();
}

/// @brief CLIENTE NAO AUTENTICADO RECEBE A RESPOSTA DE ERRO ":<servidor> 451 <comando> :Você não se registrou"
/// @brief CASO NAO ENCONTRE O CARACTER ":" NO COMANDO RESPONDE COM ":<servidor> 412 <nick> :Nenhum texto para enviar"
/// @brief SE TIVER UM NUMERO DE ARGUMENTOS DIFERENTE DE 3 RESPONDE COM O ERRO ":<servidor> 461 A PRIVMSG :Parâmetros insuficientes"
/// @brief CASO O NICK SEJA INVALIDO OU NAO EXISTE O SERVIDOR RESPONDE COM ":<servidor> 401 <enviador> <destinatário> :Nick/canal não existe"
/// @brief CASO PASSAR POR TODAS AS VERIFICACOES ACIMA REDIRECIONA A MENSAGEM PARA O NICK DESTINARARIO E NAO RESPONDE O REMETENTE
void Server::PRIVMSG(void) {
	if (this->client->auth == false) {
		this->resClient(":" + this->getIp() + " " + ERR_NOTREGISTERED + " PRIVMSG :Você não se registrou"); // You have not registered
	} else if (this->cmd.find(":") == std::string::npos || this->cmd.find(":") == this->cmd.size()) {
		this->resClient(":" + this->getIp() + " " + ERR_NOTEXTTOSEND + " " + this->client->nick + " :Nenhum texto para enviar"); // No text to send
	} else if (this->argsCmd.size() != 3) {
		this->resClient(":" + this->getIp() + " " + ERR_NEEDMOREPARAMS + this->client->nick + " PRIVMSG :Parâmetros insuficientes"); // Not enough parameters
	} else if (this->nickInvalid(this->argsCmd[1]) == true || this->nickClient[this->argsCmd[1]] == NULL) {
		this->resClient(":" + this->getIp() + " " + ERR_NOSUCHNICK + " " + this->client->nick + " " + this->argsCmd[1] + " :Nick/canal não existe"); // No such nick/channel
	} else {
		this->sendClient(":" + this->client->nick + "!" + this->client->user + "@" + this->client->getIp() + " PRIVMSG " + this->argsCmd[1] + " :" + this->argsCmd[2], nickClient[this->argsCmd[1]]);
	}
}