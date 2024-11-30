#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <vector>
#include <csignal>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <poll.h>

#include <unistd.h> // USANDO ISSO PARA VER O PID

#include "Server.hpp"
#include "Client.hpp"

extern int server_socket;

// ./src/verification.cpp
void validation(int argc, char **argv);

// ./src/server.cpp
void init_server(int port, char *password);
void listener(Server &server);

// ./src/signal.cpp
void ctrlC(int signal);

// ./src/client.cpp
// Client new_client(void); // IMPLEMENTEI ESSA FUNCAO NO CONSTRUTOR DA CLASSE Client(void)
void new_client(std::vector<pollfd> &fds, std::vector<Client> &clients, int server_socket);
void delete_client(std::vector<pollfd> &fds, std::vector<Client> &clients, unsigned int i);
void new_buffer(Client &client, std::vector<pollfd> &fds, std::string buffer);
// bool authentication(Client &client);

// ./src/password.cpp
int authPassword(int client_socket, char *passwordServer);

#endif