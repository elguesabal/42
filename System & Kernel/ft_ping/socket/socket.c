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
#include <errno.h>

/**
 * @author VAMPETA
 * @brief CRIA E ARMAZENA O sockfd
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
*/
void	create_sockfd(t_info *info)
{
	info->sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (info->sockfd == -1)
	{
		printf("ft_ping: socket: Operation not permitted\n");
		exit(ERROR);
	}
}

/**
 * @author VAMPETA
 * @brief ENVIA UM PING
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
 * @return RETORNA A MACRO SUCCESS OU ERROR
*/
ssize_t	send_ping(t_info *info)
{
	ssize_t	bytes;

	bytes = sendto(info->sockfd, info->packet, ICMP_PACKET_SIZE, 0, (struct sockaddr *)&info->addr, sizeof(info->addr));
	if (bytes < 0)
	{
		printf("ft_ping: socket: ??????\n");
		return (ERROR);
	}
	return (SUCCESS);
}
