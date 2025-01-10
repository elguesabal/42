#include "header.h"

Channel::ClientChanell::ClientChanell(Client *client) : client(client), i(false), t(false), k(false), o(false), l(false) {
    // this->client = ;
}

Channel::Channel(std::string &name) {
    // std::cout << "construtor chamado" << std::endl;

    this->name = name; // PAREI AKI
}

Channel::~Channel(void) {

}