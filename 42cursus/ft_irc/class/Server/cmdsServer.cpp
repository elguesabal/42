#include "header.h"

/// @brief SE TIVER MENOS DE DOIS PARAMETROS RESPONDE COM ":<servidor> 461 A PRIVMSG :Parâmetros insuficientes"
/// @brief SE O PARAMETRO INFORMADO NAO CORRESPONDER A UM ARQUIVO MANDA UMA MENSAGEM "Ascii art não encontrada"
/// @brief CASO NAO SEJA NENHUMA DAS OPCOES ACIMA E OCORRA TUDO CORRETAMENTE ENVIA O CONTEUDO DO ARQUIVO UMA LINHA DE CADA VEZ
void Server::asciiArt(void) {
	std::string path = "./ascii-art/" + (this->argsCmd.size() > 1 ? this->argsCmd[1] : "");
	std::ifstream file(path.c_str());

	if (this->argsCmd.size() < 2) {
		this->resClient(":" + this->getIp() + " " + ERR_NEEDMOREPARAMS + this->client->nick + " PRIVMSG :Parâmetros insuficientes"); // Not enough parameters
	} else if (!file.is_open()) {
		this->resClient(":" + this->getIp() + " NOTICE " + this->client->nick + " :Ascii art não encontrada");
	} else {
		std::string line;
		while (std::getline(file, line)) {
			this->resClient(":" + this->getIp() + " NOTICE " + this->client->nick + " :" + line);
		}
		file.close();
	}
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

/// @brief SE TIVER UM NUMERO DE ARGUMENTOS MENOR Q 2 RESPONDE COM O ERRO ":<servidor> 461 A PRIVMSG :Parâmetros insuficientes"
/// @brief SE NAO OUVER UM CANAL COM O NOME CORRESPONDENTE CRIA UM NOVO CANAL ADICIONANDO O CLIENTE COMO OPERADOR
/// @brief CASO O CANAL NAO COMECE COM '#' OU CONTENHA CARACTERES INVALIDOS RESPONDE COM ":<servidor> 403 <apelido> <canal> :Nenhum canal desse tipo"
/// @brief SE O LIMITE DO CANAL ESTIVER ATIVO E O CANAL JA ESTIVER CHEIO RESPONDE COM ":<servidor> 471 <apelido> <canal> :Não é possível entrar no canal (+l)"
/// @brief SE O CLIENTE TENTAR ENTRAR EM UM CANAL COM SENHA E FORNECER A SENHA ERRADA OU SEM FORNECER UMA SENHA RESPONDE COM ":<servidor> 475 <apelido> <canal> :Não é possível entrar no canal (+k)"
/// @brief SE NENHUMA DAS OPCOES ACIMA ACONTECER E PQ O CLIENTE VAI SER ADICIONADO EM UM CANAL JA EXISTENTE
void Server::JOIN(void) {
	std::string host = this->getIp();
	std::string nick = this->client->nick;
	std::string channel;
	std::vector<std::string> channels = this->split(this->argsCmd[1], ',');
	std::vector<std::string> password = (this->argsCmd.size() < 3 ? std::vector<std::string>() : this->split(this->argsCmd[2], ','));

	while (channels.size() > password.size()) {
		password.push_back("");
	}

	for (unsigned int i = 0; i < channels.size(); i++) {
		channel = channels[i];
		if (this->argsCmd.size() < 2) {
			this->resClient(":" + host + " " + ERR_NEEDMOREPARAMS + nick + " JOIN :Parâmetros insuficientes"); // Not enough parameters
		} else if (channel[0] != '#' || this->nickChannelInvalid(channel, " \r\n:;@!*,+-=")) {
			this->resClient(":" + host + " " + ERR_NOSUCHCHANNEL + " " + nick + " " + channel + " :Nenhum canal desse tipo"); // No such channel
		} else if (this->channels.count(channel) == 0) {
			this->creatChannel(channel); // VOU CRIAR UM vector DENTRO DO CLIENTE Q VAI GUARDAR TODOS OS CANAIS
		} else if (this->channels[channel]->l == true && this->channels[channel]->size() >= this->channels[channel]->limit) {
			this->resClient(":" + host + " " + ERR_CHANNELISFULL + " " + nick + " " + channel + " :Não é possível entrar no canal (+l)"); // Cannot join channel (+l)
		} else if (this->channels[channel]->k == true && password[i] != this->channels[channel]->password) {
			this->resClient(":" + host + " " + ERR_BADCHANNELKEY + " " + nick + " " + channel + " :Não é possível entrar no canal (+k)"); // Cannot join channel (+k)
		} else {
			this->joinChannel(channel); // VOU CRIAR UM vector DENTRO DO CLIENTE Q VAI GUARDAR TODOS OS CANAIS
		}
	}
}

/// @brief GERENCIA O COMANDO LIST SEPARANDO EM UMA BUSCA POR TODOS OS CANAIS OU POR APENAS ALGUNS ESPECIFICOS
void Server::LIST(void) {
	if (this->argsCmd.size() < 2) {
		this->listChannels();
	} else {
		this->searchChannels(this->split(this->argsCmd[1], ','));
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

/// @brief SE TIVER UM NUMERO DE ARGUMENTOS MENOR Q 2 OU O SEGUNDO ESTEJA VAZIO RESPONDE COM ":<servidor> 461 A PRIVMSG :Parâmetros insuficientes"
/// @brief SE CANAL NAO EXISTE RESPONDE COM ":<servidor> 403 <apelido> <canal> :Canal inexistente"
/// @brief SE O MANDA APENAS O NOME DO CANAL O SERVIDOR RESPONDE APENAS COM OS MODOS DO CANAL ":<servidor> 324 <apelido> <canal> <modos do canal>" E ":<servidor> 329 <apelido> <canal> <timestamp>"
/// @brief SE O CANAL EXISTE MAS O CLIENTE NAO ESTA DENTRO DELE RESPONDE COM ":<servidor> 442 <apelido> <canal> :Você não está nesse canal"
/// @brief SE O CLIENTE NAO FOR UM OPERADOR RESPONDE COM ":<servidor> 482 <apelido> <canal> :Você não é um operador de canal"
/// @brief SE O TERCEIRO ARGUMENTO NAO COMECAR COM "+" OU "-" RESPONDE COM O ERRO ":<servidor> 501 <apelido> <canal> :Bandeira MODE desconhecida"
/// @brief SE O TERCEIRO ARGUMENDO TIVER UM TAMANHO DIFERENTE DE 2 RESPONDE COM ERRO ":<servidor> 471 <apelido> <canal> :Modo desconhecido"
void Server::MODE(void) {
	std::string host = this->getIp();
	std::string nick = this->client->nick;
	std::string channel = (this->argsCmd.size() > 1 ? this->argsCmd[1] : "");
	std::string mode = (this->argsCmd.size() > 2 ? this->argsCmd[2] : "");

	if (this->argsCmd.size() < 2 || channel == "") {
		this->resClient(":" + host + " " + ERR_NEEDMOREPARAMS + nick + " MODE :Parâmetros insuficientes"); // Not enough parameters
	} else if (this->channels.count(channel) == 0) {
		this->resClient(":" + host + " " + ERR_NOSUCHCHANNEL + " " + nick + " " + channel + " :Canal inexistente"); // No such channel
	} else if (this->argsCmd.size() == 2) {
		this->resClient(":" + host + " " + RPL_CHANNELMODEIS + " " + nick + " " + channel + " " + "+" + (this->channels[channel]->i ? "i" : "") + (this->channels[channel]->t ? "t" : "") + (this->channels[channel]->k ? "k" : "") + (this->channels[channel]->l ? "l" : ""));
	} else if (this->channels[channel]->nickClient.count(nick) == 0) {
		this->resClient(":" + host + " " + ERR_NOTONCHANNEL + " " + nick + " " + channel + " :Você não está nesse canal"); // You're not on that channel
	} else if (this->channels[channel]->nickClient[nick]->o == false) {
		this->resClient(":" + host + " " + ERR_CHANOPRIVSNEEDED + " " + nick + " " + channel + " :Você não é um operador de canal"); // You're not channel operator
	} else if (mode[0] != '-' && mode[0] != '+') {
		this->resClient(":" + host + " " + ERR_UMODEUNKNOWNFLAG + " " + nick + " " + channel + " :Bandeira MODE desconhecida");
	} else if (mode.size() != 2 || (mode[1] != 'i' && mode[1] != 't' && mode[1] != 'k' && mode[1] != 'o' && mode[1] != 'l')) {
		this->resClient(":" + host + " " + ERR_UNKNOWNMODE + " " + nick + " " + channel + " :Modo desconhecido");
	} else if (mode[1] == 'i') {
		this->i(channel, (mode[0] == '+' ? true : false));
	} else if (mode[1] == 't') {
		this->t(channel, (mode[0] == '+' ? true : false));
	} else if (mode[1] == 'k') {
		this->k(channel, (mode[0] == '+' ? true : false), (this->argsCmd.size() < 4 ? "" : argsCmd[3]));
	} else if (mode[1] == 'o') {
		this->o(channel, (mode[0] == '+' ? true : false), (this->argsCmd.size() < 4 ? "" : argsCmd[3]));
	} else if (mode[1] == 'l') {
		this->l(channel, (mode[0] == '+' ? true : false), (this->argsCmd.size() < 4 ? "0" : argsCmd[3]));
	}
}

/// @brief SE O COMANDO "NICK" FOR RECEBIDO SEM O COMANDO "PASS" ANTERIORMENTE CHAMA A FUNCAO "this->unauthPass();"
/// @brief COMANDO "NICK" ENVIADO SEM NENHUM ARGUMENTO RESPONDE COM ":<servidor> 431 <nick> :Nenhum nick fornecido"
/// @brief CASO O NICK CONTENHA UM CARACTER PROIBIDO RESPONDE COM ":<servidor> 431 <nick> :Nick inválido"
/// @brief NAO RESPONDE NADA SE O CLINTE TENTAR MUDAR O NICK PARA SEU PROPRIO NICK
/// @brief CASO O NICK JA ESTE EM USO RESPONDE COM ":<servidor> 433 <nick> :O nick já está em uso"
/// @brief TROCA DE NICK COM USUARIO JA AUTENTICADO RESPONDE COM ":<antigo nick> NICK :<novo nick>"
/// @brief ATRIBUICAO DE NICK EM CLIENTE CHAMA A FUNCAO "this->assignNick();" (AGUARDA RESPOSTA DE BOAS VINDAS)
void Server::NICK(void) {
	std::string host = this->getIp();
	std::string nick = this->client->nick;
	std::string newNick = (this->argsCmd.size() > 1 ? this->argsCmd[1] : "");

	if (this->client->authPass == false) {
		this->unauthPass();
		return ;
	} else if (this->argsCmd.size() < 2) {
		this->resClient(":" + host + " " + ERR_NONICKNAMEGIVEN + " * :Nenhum nick fornecido"); // No nickname 
	} else if (this->nickChannelInvalid(newNick, " \r\n:;@!*,+-=#&")) {
		this->resClient(":" + host + " " + ERR_ERRONEUSNICKNAME " " + nick + " " + newNick + " :Nick inválido"); // Erroneous nickname
	} else if (nick == newNick) {

	} else if (this->nickInUse(newNick)) {
		this->resClient(":" + this->getIp() + " " + ERR_NICKNAMEINUSE + " " + nick + " " + newNick + " :O nick já está em uso"); // Nickname is already in use
	} else if (this->client->authNick == true) {
		this->swapNick();
	} else {
		this->assignNick();
	}
	this->authentication();
}					// E SE UM NICK FOR TROCADO COMO FICA OS CANAIS?? VAI BUGAR TUDO SE UM MEMBRO ENTRAR EM UM CANAL E DPS TROCAR DE NICK

/// @brief 
void Server::PART(void) {
std::cout << "comando: '" << this->cmd << "'" << std::endl;


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
	if (this->argsCmd.size() < 2) {
		this->resClient(":" + this->getIp() + " " + ERR_NOORIGIN + " " + this->client->nick + " :Nenhuma origem especificada"); // No origin specified
	} else {
		this->resClient(":" + this->getIp() + " PONG ft_irc :" + this->argsCmd[1]);
	}
}

/// @brief CASO NAO ENCONTRE O CARACTER ":" NO COMANDO RESPONDE COM ":<servidor> 412 <nick> :Nenhum texto para enviar"
/// @brief SE TIVER UM NUMERO DE ARGUMENTOS DIFERENTE DE 3 RESPONDE COM O ERRO ":<servidor> 461 A PRIVMSG :Parâmetros insuficientes"
/// @brief CASO O NICK NAO RETORNE NULL AO SER USADO COMO CHAVE DENTRO DE "this->nickClient" REDIRECIONA A MENSAGEM PARA O NICK DESTINARARIO E NAO RESPONDE O REMETENTE ":<apelido>!<usuario>@<host> PRIVMSG <apelido> :<mensagem>"
/// @brief CAOS O CLIENTE TENTE MANDAR MENSAGEM EM UM CANAL Q ELE NAO E MEMBRO RESPONDE COM ":<servidor> 404 <apelido> <canal> :Você não participa deste canal"
/// @brief CASO O NICK NAO RETORNE NULL AO SER USADO COMO CHAVE DENTRO DE "this->channel" REDIRECIONA A MENSAGEM PARA OS MEMBROS DO CANAL ":<apelido>!<usuario>@<host> PRIVMSG <canal> :<mensagem>" (NAO ENVIA A SI MESMO)
/// @brief CASO O NICK PASSE POR TODAS AS VERIFICACOES ELE NAO EXISTE E O SERVIDOR RESPONDE COM ":<servidor> 401 <enviador> <destinatário> :Nick/canal não existe"
void Server::PRIVMSG(void) {
	if (this->cmd.find(":") == std::string::npos || this->cmd.find(":") == this->cmd.size()) {
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

/// @brief SE TIVER UM NUMERO DE ARGUMENTOS MENOR Q 2 OU O SEGUNDO ESTEJA VAZIO RESPONDE COM ":<servidor> 461 A PRIVMSG :Parâmetros insuficientes"
/// @brief SE CANAL NAO EXISTE RESPONDE COM ":<servidor> 403 <apelido> <canal> :Canal inexistente"
/// @brief SE OUVER APENAS 2 ARGUMENTOS RESPONDE COM ":<servidor> 332 <apelido> <canal> :<tópico do canal>" OU ":<servidor> 331 <apelido> <canal> :No topic is set"
/// @brief SE O CLIENTE TENTAR MUDAR O TOPICO E NAO ESTIVER NO CANAL RESPONDE COM ":<servidor> 442 <apelido> <canal> :Você não está nesse canal"
/// @brief SE O MODO +t ESTIVER ATIVO E UM MEMBRO Q NAO SEJA UM OPERADOR TENTAR MUDAR O TOPICO RESPONDE COM ":<servidor> 482 <apelido> <canal> :Você não é um operador de canal"
/// @brief SE O TOPICO FOR MUDADO COM SUCESSO RESPONDE COM ":<apelido>!<usuario>@<host> TOPIC <canal> :<tópico>"
void Server::TOPIC(void) {
	std::string host = this->getIp();
	std::string nick = this->client->nick;
	std::string channel = (this->argsCmd.size() > 1 ? this->argsCmd[1] : "");
	std::string topic = (this->argsCmd.size() > 2 ? this->argsCmd[2] : "");

	if (this->argsCmd.size() < 2 || channel == "") {
		this->resClient(":" + host + " " + ERR_NEEDMOREPARAMS + nick + " MODE :Parâmetros insuficientes"); // Not enough parameters
	} else if (this->channels.count(channel) == 0) {
		this->resClient(":" + host + " " + ERR_NOSUCHCHANNEL + " " + nick + " " + channel + " :Canal inexistente"); // No such channel
	} else if (this->argsCmd.size() < 3) {
		this->resClient(":" + host + " " + (this->channels[channel]->topic != "" ? RPL_TOPIC : RPL_NOTOPIC) + " " + nick + " " + channel + " :" + (this->channels[channel]->topic != "" ? this->channels[channel]->topic : "Nenhum tópico está definido")); // No topic is set
	} else if (this->channels[channel]->nickClient.count(nick) == 0) {
		this->resClient(":" + host + " " + ERR_NOTONCHANNEL + " " + nick + " " + channel + " :Você não está nesse canal"); // You're not on that channel
	} else if (this->channels[channel]->t == true && this->channels[channel]->nickClient[nick]->o == false) {
		this->resClient(":" + host + " " + ERR_CHANOPRIVSNEEDED + " " + nick + " " + channel + " :Você não é um operador de canal"); // You're not channel operator
	} else {
		this->channels[channel]->topic = topic;
		this-> resChannel(":" + nick + "!" + this->client->user + "@" + this->client->getIp() + " TOPIC " + channel + " :" + topic, this->channels[channel]);
	}
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