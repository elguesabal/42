#include "header.h"

/// @brief FUNCAO Q BUSCA O IP DO SERVIDOR
/// @return RETORNA O IP DO SERVIDOR
std::string Server::getIp(void) const {
	// char hostname[1024];
	// if (gethostname(hostname, sizeof(hostname)) == -1) {
	// 	std::cout << "Error: gethostname" << std::endl;
	// 	return "Unknown";
	// }

	// struct addrinfo hints, *res;
	// memset(&hints, 0, sizeof(hints));
	// hints.ai_family = AF_INET; // IPv4
	// hints.ai_socktype = SOCK_STREAM;

	// if (getaddrinfo(hostname, NULL, &hints, &res) != 0) {
	// 	std::cout << "Error: getaddrinfo" << std::endl;
	// 	return "Unknown";
	// }

	// char ip[INET_ADDRSTRLEN];
	// struct sockaddr_in *addr = (struct sockaddr_in *)res->ai_addr;
	// inet_ntop(AF_INET, &(addr->sin_addr), ip, INET_ADDRSTRLEN);

	// freeaddrinfo(res);
	// return std::string(ip);

	return ("192.168.137.155"); // NAO CONSEGI PEGAR O IP DO PROPRIO SERVIDOR ENTAO TO FZND ISSO PRA TENTAR DPS
}