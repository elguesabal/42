#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <csignal>
#include <algorithm>
// #include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <poll.h>

#include "Server.hpp"
#include "Client.hpp"

// extern int server_socket;

// ./src/verification.cpp
void validation(int argc, char **argv);

// ./src/signal.cpp
void ctrlC(int signal);

// ./src/server.cpp
// void init_server(int port, char *password); // A TAREFA DESSA FUNCAO FOI PASSADA PARA O CONSTRUTOR Server
void listener(Server &server);

// ./src/client.cpp
// void new_client(Server &server); // ESSA FUNCAO VIROU METODO DA CLASSE Server
// void delete_client(Server &server, Client &client);
void new_buffer(Server &server, Client &client);
void authentication(Server &server, Client &client);

#endif