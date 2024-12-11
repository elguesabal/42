#include <iostream>
#include <sys/socket.h>
#include <netdb.h>
#include <cstring>
#include <arpa/inet.h>

// int getaddrinfo(const char *node, const char *service, const struct addrinfo *hints, struct addrinfo **res);
// void freeaddrinfo(struct addrinfo *res);
// int main(void) {
// 	struct addrinfo hints, *res;
// 	memset(&hints, 0, sizeof(hints));
// 	hints.ai_family = AF_INET; // IPv4
// 	hints.ai_socktype = SOCK_STREAM; // TCP

// 	if (getaddrinfo("google.com", "https", &hints, &res) != 0) {
// 		perror("getaddrinfo");
// 		return (1);
// 	}

// 	char ip[INET_ADDRSTRLEN];
// 	struct sockaddr_in *addr = (struct sockaddr_in *)res->ai_addr;
// 	inet_ntop(AF_INET, &(addr->sin_addr), ip, sizeof(ip));

// 	std::cout << "IP Address: " << ip << std::endl;

// 	freeaddrinfo(res); // Libera a memória alocada
// 	return (0);
// }



// struct hostent *gethostbyname(const char *name);
// int main(void) {
// 	struct hostent *host = gethostbyname("google.com");
// 	if (!host) {
// 		perror("gethostbyname");
// 		return (1);
// 	}

// 	char ip[INET_ADDRSTRLEN];
// 	inet_ntop(AF_INET, host->h_addr_list[0], ip, sizeof(ip));

// 	std::cout << "IP Address: " << ip << std::endl;
// 	return (0);
// }



// struct protoent *getprotobyname(const char *name);
// int main(void) {
// 	struct protoent *proto = getprotobyname("tcp");
// 	if (!proto) {
// 		perror("getprotobyname");
// 		return (1);
// 	}

// 	std::cout << "Protocol Name: " << proto->p_name << std::endl;
// 	std::cout << "Protocol Number: " << proto->p_proto << std::endl;

// 	return (0);
// }