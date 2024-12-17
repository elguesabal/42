#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <csignal>
#include <algorithm>
#include <sstream>
#include <set>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <poll.h>

#include "Server.hpp"
#include "Client.hpp"

// #include <stdio.h> // printf()

// extern int server_socket;

// ./src/verification.cpp
void validation(int argc, char **argv);

// ./src/signal.cpp
void ctrlC(int signal);

// ./src/utils.cpp
void splitMessage(Server &server);

// ./src/server.cpp
// void init_server(int port, char *password); // A TAREFA DESSA FUNCAO FOI PASSADA PARA O CONSTRUTOR Server
// void listener(Server &server); // ESSA FUNCAO VIROU UM METODO DA CLASSE Server

// ./src/client.cpp
// void new_client(Server &server); // ESSA FUNCAO VIROU METODO DA CLASSE Server
// void delete_client(Server &server, Client &client); // ESSA FUNCAO VIROU METODO DA CLASSE Server
// void new_buffer(Server &server, Client &client); // ESSA FUNCAO VIROU UM METODO DA CLASSE Server
// void authentication(Server &server, Client &client); // ESSA FUNCAO VIROU UM METODO DA CLASSE Server

#endif