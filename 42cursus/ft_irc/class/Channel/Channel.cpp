#include "header.h"

/// @brief CONSTRUTOR DO STRUCT ClientChannel
/// @param client CLIENTE Q VAI CRIAR O CANAL
Channel::ClientChanell::ClientChanell(Client *client) : client(client), o(false) {

}

/// @brief CONSTRUTOR DA CLASSE Channel
/// @param client CLIENTE Q VAI CRIAR O CANAL
Channel::Channel(std::string &name, Client *client) : name(name), i(false), t(false), k(false), l(false), topic("") {
	this->newMember(client);
	this->clients[0]->o = true;
	this->operators.push_back(client->nick);
}

/// @brief DESTRUTOR DA CLASSE
Channel::~Channel(void) {
	// AKI EU TENHO Q USAR delete NO std::vector<ClientChanell *> clients
}

/// @brief ADICIONA UM CLIENTE A LISTA DE MEMBROS DO CANAL
/// @param client CLIENTE A SER ADICIONADO
void Channel::newMember(Client *client) {
	try {
		ClientChanell *newClient = new ClientChanell(client);

		this->clients.push_back(newClient);
		this->nickClient[client->nick] = newClient;
	} catch (const std::exception &error) {
		throw ;
	}
}



/// @brief VERIFICA SE O CLIENTE E UM OPERADOR
/// @param client NOME DO CLIENTE A SER VERIFICADO
/// @return RETONAR SE O CLIENTE E UM OPERADOR (true OU false)
bool Channel::isOperator(std::string &client) {
	// return (std::find(this->operators.begin(), this->operators.end(), client) == this->operators.end());
	return (!this->nickClient[client]->o); // SE NAO OUVER UMA CHAVE E EU TENTAR ACESSAR UM ELEMENTO AI O std::map CRIA UM ELEMENTO NA CHAVE PRA NAO DAR ERRO
}