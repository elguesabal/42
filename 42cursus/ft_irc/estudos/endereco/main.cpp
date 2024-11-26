#include <arpa/inet.h>
#include <iostream>

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
int main(void) {
	struct in_addr ip_addr;
	ip_addr.s_addr = inet_addr("192.168.0.1");
	char *ip_str = inet_ntoa(ip_addr);
	std::cout << "endereco ip: " << ip_str << std::endl;
	return (0);
}