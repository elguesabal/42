#include "header.h"

/// @brief SE TIVER MENOS DE DOIS PARAMETROS RESPONDE COM ":<servidor> 461 A PRIVMSG :Parâmetros insuficientes"
/// @brief SE O PARAMETRO INFORMADO NAO CORRESPONDER A UM ARQUIVO MANDA UMA MENSAGEM "Ascii art não encontrada"
/// @brief CASO NAO SEJA NENHUMA DAS OPCOES ACIMA E OCORRA TUDO CORRETAMENTE ENVIA O CONTEUDO DO ARQUIVO UMA LINHA DE CADA VEZ
void Server::asciiArt(void) {
	if (this->argsCmd.size() < 2) {
		this->resClient(":" + this->getIp() + " " + ERR_NEEDMOREPARAMS + this->client->nick + " PRIVMSG :Parâmetros insuficientes"); // Not enough parameters
		return ;
	}

	std::string path = "./ascii-art/" + this->argsCmd[1];
	std::ifstream file(path.c_str());
	if (!file.is_open()) {
		this->resClient(":" + this->getIp() + " NOTICE " + this->client->nick + " :Ascii art não encontrada");
		return ;
	}
	std::string line;
	while (std::getline(file, line)) {
		this->resClient(":" + this->getIp() + " NOTICE " + this->client->nick + " :" + line);
	}
	file.close();
}

/// @brief COMANDO DE NEGOCIACAO DE CAPACIDADES "CAP LS 302" RESPONDE COM ":<servidor> CAP <nick> LS :"
/// @brief "CAP END" NAO RESPONDE (FIM DA NEGOCIACAO DE CAPACIDADES)
void Server::CAP(void) {
	if (this->cmd == "CAP LS 302") {
		this->resClient(":" + this->getIp() + " CAP * LS :ascii-art");
		this->resClient(":" + this->getIp() + " CAP * ACK :ascii-art");
	} else if (this->cmd == "CAP END") {

	}
}

/// @brief SE O ARQUIVO "./ascii-art/luana" NAO EXISTIR RESPONDE COM "Arquivo não encontrado"
/// @brief CASO TUDO OCORRA CORRETAMENTE ENVIA O CONTEUDO DO ARQUIVO UMA LINHA DE CADA VEZ
void Server::luana(void) {
	std::ifstream file("./ascii-art/luana");
	if (!file.is_open()) {
		this->resClient(":" + this->getIp() + " NOTICE " + this->client->nick + " :Arquivo não encontrado");
		return ;
	}
	std::string line;
	while (std::getline(file, line)) {
		this->resClient(":" + this->getIp() + " NOTICE " + this->client->nick + " :" + line);
	}
	file.close();
}

/// @brief SE O COMANDO "NICK" FOR RECEBIDO SEM O COMANDO "PASS" ANTERIORMENTE REPONDE COM ":<servidor> 464 <nick> :Senha necessária" E FECHA A CONEXAO
/// @brief COMANDO "NICK" ENVIADO SEM NENHUM ARGUMENTO RESPONDE COM ":<servidor> 431 <nick> :Nenhum nick fornecido"
/// @brief CASO O NICK CONTENHA UM CARACTER PROIBIDO RESPONDE COM ":<servidor> 431 <nick> :Nick inválido"
/// @brief NAO RESPONDE NADA SE O CLINTE TENTAR MUDAR O NICK PARA SEU PROPRIO NICK
/// @brief CASO O NICK JA ESTE EM USO RESPONDE COM ":<servidor> 433 <nick> :O nick já está em uso"
/// @brief TROCA DE NICK COM USUARIO JA AUTENTICADO RESPONDE COM ":<antigoNick> NICK :<novoNick>"
/// @brief INSERCAO DE NICK EM CLIENTE NAO AUTENTICADO NAO TEM RESPOSTA (AGUARDA RESPOSTA DE BOASS VINDAS)
void Server::NICK(void) {
	if (this->client->authPass == false) {
		this->resClient(":" + this->getIp() + " " + ERR_PASSWDMISMATCH + " * :Senha necessária"); // Password required
		this->deleteClient();
	} else if (this->argsCmd.size() < 2) {
		this->resClient(":" + this->getIp() + " " + ERR_NONICKNAMEGIVEN + " * :Nenhum nick fornecido"); // No nickname 
	} else if (this->nickChannelInvalid(this->argsCmd[1], " \r\n:;@!*,+-=#&")) {
		this->resClient(":" + this->getIp() + " " + ERR_ERRONEUSNICKNAME " " + this->client->nick + " " + this->argsCmd[1] + " :Nick inválido"); // Erroneous nickname
	} else if (this->client->nick == this->argsCmd[1]) {

	} else if (this->nickInUse(this->argsCmd[1])) {
		this->resClient(":" + this->getIp() + " " + ERR_NICKNAMEINUSE + " " + this->client->nick + " " + this->argsCmd[1] + " :O nick já está em uso"); // Nickname is already in use
	} else if (this->client->authNick == true) {
		this->resClient(":" + this->client->nick + " NICK :" + this->argsCmd[1]);
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

/// @brief CLIENTE NAO AUTENTICADO RECEBE A RESPOSTA DE ERRO ":<servidor> 451 <comando> :Você não se registrou"
/// @brief CASO NAO ENCONTRE O CARACTER ":" NO COMANDO RESPONDE COM ":<servidor> 412 <nick> :Nenhum texto para enviar"
/// @brief SE TIVER UM NUMERO DE ARGUMENTOS DIFERENTE DE 3 RESPONDE COM O ERRO ":<servidor> 461 A PRIVMSG :Parâmetros insuficientes"
/// @brief CASO O NICK NAO RETORNE NULL AO SER USADO COMO CHAVE DENTRO DE "this->nickClient" REDIRECIONA A MENSAGEM PARA O NICK DESTINARARIO E NAO RESPONDE O REMETENTE ":<apelido>!<usuario>@<host> PRIVMSG <apelido> :<mensagem>"
/// @brief CAOS O CLIENTE TENTE MANDAR MENSAGEM EM UM CANAL Q ELE NAO E MEMBRO RESPONDE COM ":<servidor> 404 <apelido> <canal> :Você não participa deste canal"
/// @brief CASO O NICK NAO RETORNE NULL AO SER USADO COMO CHAVE DENTRO DE "this->channel" REDIRECIONA A MENSAGEM PARA OS MEMBROS DO CANAL ":<apelido>!<usuario>@<host> PRIVMSG <canal> :<mensagem>" (NAO ENVIA A SI MESMO)
/// @brief CASO O NICK PASSE POR TODAS AS VERIFICACOES ELE NAO EXISTE E O SERVIDOR RESPONDE COM ":<servidor> 401 <enviador> <destinatário> :Nick/canal não existe"
void Server::PRIVMSG(void) {
	if (this->client->auth == false) {
		this->resClient(":" + this->getIp() + " " + ERR_NOTREGISTERED + " PRIVMSG :Você não se registrou"); // You have not registered
	} else if (this->cmd.find(":") == std::string::npos || this->cmd.find(":") == this->cmd.size()) {
		this->resClient(":" + this->getIp() + " " + ERR_NOTEXTTOSEND + " " + this->client->nick + " :Nenhum texto para enviar"); // No text to send
	} else if (this->argsCmd.size() != 3) {
		this->resClient(":" + this->getIp() + " " + ERR_NEEDMOREPARAMS + this->client->nick + " PRIVMSG :Parâmetros insuficientes"); // Not enough parameters
	} else if (this->nickClient.count(this->argsCmd[1]) == 1) {
		this->sendClient(":" + this->client->nick + "!" + this->client->user + "@" + this->client->getIp() + " PRIVMSG " + this->argsCmd[1] + " :" + this->argsCmd[2], this->nickClient[this->argsCmd[1]]);
	} else if (this->channels.count(this->argsCmd[1]) == 1 && this->channels[this->argsCmd[1]]->nickClient.count(this->client->nick) == 0) {
		this->resClient(":" + this->getIp() + " " + ERR_CANNOTSENDTOCHAN + " " + this->client->nick + " " + this->argsCmd[1] + " :Você não participa deste canal"); // Cannot send to channel
	} else if (this->channels.count(this->argsCmd[1]) == 1) {
		this->sendChannel(":" + this->client->nick + "!" + this->client->user + "@" + this->client->getIp() + " PRIVMSG " + this->argsCmd[1] + " :" + this->argsCmd[2], this->channels[this->argsCmd[1]]);
	} else {
		this->resClient(":" + this->getIp() + " " + ERR_NOSUCHNICK + " " + this->client->nick + " " + this->argsCmd[1] + " :Nick/canal não existe"); // No such nick/channel
	}
}

/// @brief DESCONECTA O CLIENTE (AINDA NAO NOTIFICA OS CANAIS PQ AINDA NAO EMPLEMENTEI)
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






/// @brief SE TIVER UM NUMERO DE ARGUMENTOS MENOR Q 2 RESPONDE COM O ERRO ":<servidor> 461 A PRIVMSG :Parâmetros insuficientes"
/// @brief SE NAO OUVER UM CANAL COM O NOME CORRESPONDENTE CRIA UM NOVO CANAL ADICIONANDO O CLIENTE COMO OPERADOR
/// @brief CASO O CANAL NAO COMECE COM '#' OU CONTENHA CARACTERES INVALIDOS RESPONDE COM ":<servidor> 403 <apelido> <canal> :Nenhum canal desse tipo"
/// @brief 
/// @brief SE NENHUMA DAS OPCOES ACIMA ACONTECER E PQ O CLIENTE VAI SER ADICIONADO EM UM CANAL JA EXISTENTE
void Server::JOIN(void) {
	// std::cout << "\033[33mWarning:\033[0m '" << this->cmd << "'" << std::endl;

	std::vector<std::string> channel = this->split(this->argsCmd[1], ',');
	std::vector<std::string> password = (this->argsCmd.size() < 3 ? std::vector<std::string>() : this->split(this->argsCmd[2], ','));

	for (unsigned int i = 0; i < channel.size(); i++) {
		// std::cout << "channel[" << i << "]: '" << channel[i] << "'" << std::endl;
		// if (i < password.size()) {
		// 	std::cout << "password[" << i << "]: '" << password[i] << "'" << std::endl;
		// }

		if (this->argsCmd.size() < 2) {
// :<servidor> 461 <apelido> JOIN :Not enough parameters
			this->resClient(":" + this->getIp() + " " + ERR_NEEDMOREPARAMS + this->client->nick + " JOIN :Parâmetros insuficientes"); // Not enough parameters
		} else if (channel[i][0] != '#' || this->nickChannelInvalid(channel[i], " \r\n:;@!*,+-=")) {
// :<servidor> 403 <apelido> <canal> :No such channel
			this->resClient(":" + this->getIp() + " " + ERR_NOSUCHCHANNEL + " " + this->client->nick + " " + channel[i] + " :Nenhum canal desse tipo"); // No such channel
		} else if (this->channels.count(channel[i]) == 0) {
			this->creatChannel(channel[i]);
		} else if (this->channels[channel[i]]->l == true && this->channels[channel[i]]->size() >= this->channels[channel[i]]->limit) { // VERIFICAR SE ESSA LOGICA ESTA CORRETA
// std::cout << "canal cheio" << std::endl;
// :<servidor> 471 <apelido> <canal> :Cannot join channel (+l)
		} else {
			this->joinChannel(channel[i], password[i]);
		}
	}
}

/// @brief SE TIVER UM NUMERO DE ARGUMENTOS MENOR Q 2 OU O SEGUNDO ESTEJA VAZIO RESPONDE COM ":<servidor> 461 A PRIVMSG :Parâmetros insuficientes"
/// @brief SE CANAL NAO EXISTE RESPONDE COM ":<servidor> 403 <apelido> <canal> :Canal inexistente"
/// @brief SE O MANDA APENAS O NOME DO CANAL O SERVIDOR RESPONDE APENAS COM OS MODOS DO CANAL ":<servidor> 324 <apelido> <canal> <modos do canal>"
/// @brief SE O CANAL EXISTE MAS O CLIENTE NAO ESTA DENTRO DELE RESPONDE COM ":<servidor> 442 <apelido> <canal> :Você não está nesse canal"
/// @brief SE O CLIENTE NAO FOR UM OPERADOR RESPONDE COM ":<servidor> 482 <apelido> <canal> :Você não é um operador de canal"
/// @brief SE O TERCEIRO ARGUMENTO NAO COMECAR COM "+" OU "-" RESPONDE COM O ERRO ":<servidor> 501 <apelido> <canal> :Bandeira MODE desconhecida"
/// @brief SE O TERCEIRO ARGUMENDO TIVER UM TAMANHO DIFERENTE DE 2 RESPONDE COM ERRO ":<servidor> 471 <apelido> <canal> :Modo desconhecido"
void Server::MODE(void) {
	// std::cout << "chegou esse comando: '" << this->cmd << "'" << "\tthis->argsCmd.size(): '" << this->argsCmd.size() << "'" << std::endl;
// std::cout << "comando: '" << this->cmd << "'" << std::endl;

	std::string host = this->getIp();
	std::string nick = this->client->nick;
	std::string channel = this->argsCmd[1];
	std::string mode = (this->argsCmd.size() > 2 ? this->argsCmd[2] : "");

	if (this->argsCmd.size() < 2 || channel == "") {
// :<servidor> 461 <apelido> MODE :Not enough parameters
		this->resClient(":" + host + " " + ERR_NEEDMOREPARAMS + nick + " MODE :Parâmetros insuficientes"); // Not enough parameters
	} else if (this->channels.count(channel) == 0) {
// :<servidor> 403 <apelido> <canal> :No such channel
		this->resClient(":" + host + " " + ERR_NOSUCHCHANNEL + " " + nick + " " + channel + " :Canal inexistente"); // No such channel
	} else if (this->argsCmd.size() == 2) {
// :<servidor> 324 <apelido> <canal> <modos do canal>
		this->resClient(":" + host + " " + RPL_CHANNELMODEIS + " " + nick + " " + channel + " " + "+t");
	} else if (this->channels[channel]->nickClient.count(nick) == 0) {
// :<servidor> 442 <apelido> <canal> :You're not on that channel
		this->resClient(":" + host + " " + ERR_NOTONCHANNEL + " " + nick + " " + channel + " :Você não está nesse canal"); // You're not on that channel
	} else if (this->channels[channel]->nickClient[nick]->o == false) {
// :<servidor> 482 <apelido> <canal> :You're not channel operator
		this->resClient(":" + host + " " + ERR_CHANOPRIVSNEEDED + " " + nick + " " + channel + " :Você não é um operador de canal");
	} else if (mode[0] != '-' && mode[0] != '+') {
// :<servidor> 501 <apelido> <canal> :Unknown MODE flag
		this->resClient(":" + host + " " + ERR_UMODEUNKNOWNFLAG + " " + nick + " " + channel + " :Bandeira MODE desconhecida");
	} else if (mode.size() != 2 || (mode[1] != 'i' && mode[1] != 't' && mode[1] != 'k' && mode[1] != 'o' && mode[1] != 'l')) {
// :<servidor> 471 <apelido> <canal> :Unknown mode
		this->resClient(":" + host + " " + ERR_UNKNOWNMODE + " " + nick + " " + channel + " :Modo desconhecido");
	} else if (mode[1] == 'i') { // ACHO Q EU SO FAREI ESSE QUANDO FIZER O COMANDO LIST
		
	} else if (mode[1] == 't') {
		
	} else if (mode[1] == 'k') {
		this->k(channel, (mode[0] == '+' ? true : false), (mode[0] == '+' ? argsCmd[3] : ""));
	} else if (mode[1] == 'o') { // AKI EU AINDA NAO VERIFIQUEI SE TEM 3 ARGUMENTOS // FALTA VERIFICAR SE O USUARIO EXISTE (E TALVES VERIFICAR SE ELE ESTA NO CANAL)
		this->o(channel, (mode[0] == '+' ? true : false), (mode[0] == '+' ? argsCmd[3] : ""));
	} else if (mode[1] == 'l') {
		
	}
}

// i t k o l