#include "../ft_ping.h"

void	test_socket(void)
{
	int	sockfd;

	sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if(sockfd < 0)
		printf("Erro ao criar socket");
	else
		printf("Socket criado");
}
