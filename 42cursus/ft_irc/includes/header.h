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
#include <ctime>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <poll.h>

#include "macros.h"
#include "Server.hpp"
#include "Client.hpp"
#include "Channel.hpp"

extern bool shutdownServer;

// ./src/signal.cpp
void ctrlC(int signal);

#endif