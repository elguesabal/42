#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <csignal>
#include <algorithm>
#include <sstream>
#include <map>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <poll.h>

#include "macros.h"
#include "Server.hpp"
#include "Client.hpp"

// ./src/verification.cpp
void validation(int argc, char **argv);

// ./src/signal.cpp
void ctrlC(int signal);

// ./src/utils.cpp
void splitMessage(Server &server);
bool nickInvalid(std::string &nick, std::map<std::string, void (Server::*)()> &commands);

#endif