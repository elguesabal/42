#include "header.h"

/// @brief PEGA O FD DO SERVIDOR
/// @return RETORNA O FD DO SERVIDOR
int Server::getFd(void) const {
	return (this->pfd.fd);
}

/// @brief METODO Q BUSCA O IP DO SERVIDOR
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
	// return ("127.0.0.1"); // LOCALHOST
	// return ("192.168.137.163");
}

/// @brief PEGA A DATA Q INICIOU O SERVIDOR
/// @return RETORNA A DATA NO FORMATO "DD/MM/AAAA"
std::string Server::getDate(void) const {
	std::ostringstream date;

	date << std::setfill('0') << std::setw(2) << this->time->tm_mday << "/" << std::setfill('0') << std::setw(2) << this->time->tm_mon + 1 << "/" << std::setfill('0') << std::setw(4) << this->time->tm_year + 1900;
	return (date.str());
}

/// @brief PEGA A HORA Q INICIOU O SERVIDOR
/// @return RETORNA A HORA NO FORMATO "HH\:MM\:SS"
std::string Server::getTime(void) const {
	std::ostringstream time;

	time << std::setfill('0') << std::setw(2) << this->time->tm_hour << ":" << std::setfill('0') << std::setw(2) << this->time->tm_min << ":" << std::setfill('0') << std::setw(2) << this->time->tm_sec;
	return (time.str());
}
