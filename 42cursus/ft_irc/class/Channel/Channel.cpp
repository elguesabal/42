#include "header.h"

/// @brief 
Channel::ClientChanell::ClientChanell(Client *client) : client(client), o(false) {

}

/// @brief 
Channel::Channel(std::string &name, Client *creator) : name(name), topic("") {
	// this->name = name;

	this->clients.push_back(ClientChanell(creator));
	this->clients[0].o = true;
}

/// @brief 
Channel::~Channel(void) {

}

/// @brief 
void Channel::addClient(Client *client) {
	this->clients.push_back(ClientChanell(client));
}