/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 13:15:19 by joseanto          #+#    #+#             */
/*   Updated: 2026/07/14 11:32:17 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ping.h"

void	test_socket(void)
{
	int	sockfd;

	sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sockfd < 0)
		printf("Erro ao criar socket\n");
	else
		printf("Socket criado\n");
}
