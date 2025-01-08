#include "header.h"

Channel::ClientChanell::ClientChanell(Client *client) : client(client), i(false), t(false), k(false), o(false), l(false) {
    // this->client = ;
}

Channel::Channel(void) {
    // std::cout << "construtor chamado" << std::endl;

    this->name = "nome do canal"; // PAREI AKI
}

Channel::~Channel(void) {

}