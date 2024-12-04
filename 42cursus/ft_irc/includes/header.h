#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <vector>
#include <csignal>
#include <algorithm>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <poll.h>

#include <unistd.h> // USANDO ISSO PARA VER O PID

#include "Server.hpp"
#include "Client.hpp"

extern int server_socket;


// bool operator == (const pollfd &fd1, const pollfd &fd2) {
// 	return (fd1.fd == fd2.fd);
// }


// ./src/verification.cpp
void validation(int argc, char **argv);

// ./src/server.cpp
void init_server(int port, char *password);
void listener(Server server);

// ./src/signal.cpp
void ctrlC(int signal);

// ./src/client.cpp
// Client new_client(void); // IMPLEMENTEI ESSA FUNCAO NO CONSTRUTOR DA CLASSE Client(void)
void new_client(std::vector<pollfd> &fds, std::vector<Client> &clients, int server_socket);
// void delete_client(std::vector<pollfd> &fds, std::vector<Client> &clients, unsigned int i, Client &client);
void delete_client(std::vector<pollfd> &fds, std::vector<Client> &clients, Client &client);
void new_buffer(Server &server, Client &client, std::vector<pollfd> &fds, std::string buffer);
// bool authentication(Client &client);

// ./src/password.cpp
int authPassword(int client_socket, char *passwordServer);

#endif