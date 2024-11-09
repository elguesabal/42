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

// struct signalData {
// 	int server_socket;
// };

int server_socket;

// ./signal.cpp
void ctrlC(int signal);

#endif