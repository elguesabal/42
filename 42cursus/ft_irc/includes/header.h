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

#include <unistd.h> // USANDO ISSO PARA VER O PID

#include "client.hpp"

// struct signalData {
// 	int server_socket;
// };

extern int server_socket;

// ./src/verification.cpp
void validation(int argc, char **argv);

// ./src/signal.cpp
void ctrlC(int signal);

// ./src/new_client.cpp
Client new_client(void);

// ./src/password.cpp
int authPassword(int client_socket, char *passwordServer);

#endif