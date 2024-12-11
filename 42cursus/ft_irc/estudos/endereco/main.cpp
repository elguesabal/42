#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>

// uint16_t htons(uint16_t hostshort);
// int main(void) {
// 	unsigned short port = 8080;
// 	unsigned short network_port = htons(port);
// 	std::cout << "porta host: " << port << ", porta rede: " << network_port << std::endl;
// 	return (0);
// }



// uint16_t ntohs(uint16_t netshort);
// int main(void) {
// 	unsigned short netword_port = htons(8080);
// 	unsigned short host_port = ntohs(netword_port);
// 	std::cout << "porta rede: " << netword_port << ", porta host: " << host_port << std::endl;
// 	return (0);
// }



// uint32_t htonl(uint32_t hostlong);
// int main(void) {
// 	unsigned long ip = 0xC0A80001; // 192.168.0.1 EM HEXADECIMAL
// 	unsigned long network_ip = htonl(ip);
// 	std::cout << "ip host: " << std::hex << ip << ", ip rede: " << network_ip << std::endl;
// 	return (0);
// }



// uint32_t ntohl(uint32_t netlong);
// int main(void) {
// 	unsigned long netword_ip = htonl(0xC0A80001); // 192.168.0.1 EM HEXADECIMAL
// 	unsigned long host_ip = ntohl(netword_ip);
// 	std::cout << "ip rede: " << std::hex << netword_ip << ", ip host: " << host_ip << std::endl;
// 	return (0);
// }



// in_addr_t inet_addr(const char *cp);
// int main(void) {
// 	const char *ip_str = "192.168.0.1";
// 	in_addr_t ip = inet_addr(ip_str);
// 	if (ip == INADDR_NONE) {
// 		std::cerr << "endereço IP invalido" << std::endl;
// 	} else {
// 		std::cout << "ip convertido: " << std::hex << ip << std::endl;
// 	}
// 	return (0);
// }



// char *inet_ntoa(struct in_addr in);
// int main(void) {
// 	struct in_addr ip_addr;
// 	ip_addr.s_addr = inet_addr("192.168.0.1");
// 	char *ip_str = inet_ntoa(ip_addr);
// 	std::cout << "endereco ip: " << ip_str << std::endl;
// 	return (0);
// }



// int getsockname(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int main(void) {
	// Cria o socket
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		perror("socket");
		return 1;
	}

	// Configura o endereço de destino
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(8080);  // Porta 8080
	server_addr.sin_addr.s_addr = INADDR_ANY;  // Qualquer endereço disponível

	// Associa o socket ao endereço local
	if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
		perror("bind");
		close(sockfd);
		return 1;
	}

	// Obtém o endereço local do socket
	struct sockaddr_in local_addr;
	socklen_t addr_len = sizeof(local_addr);
	if (getsockname(sockfd, (struct sockaddr *)&local_addr, &addr_len) == -1) {
		perror("getsockname");
		close(sockfd);
		return 1;
	}

	// Exibe o endereço IP e a porta local
	char ip_str[INET_ADDRSTRLEN];
	inet_ntop(AF_INET, &(local_addr.sin_addr), ip_str, sizeof(ip_str));
	std::cout << "Endereço local: " << ip_str << ":" << ntohs(local_addr.sin_port) << std::endl;

	// Fecha o socket
	close(sockfd);
	return (0);
}