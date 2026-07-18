/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 13:15:19 by joseanto          #+#    #+#             */
/*   Updated: 2026/07/17 17:52:58 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ping.h"

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
	printf("PING %s (%s): ", info->host, info->ip);
	printf("%i data bytes", ICMP_PAYLOAD_SIZE);
	if (info->verbose)
		printf(", id 0x%04x = %u", info->pid, info->pid);
	printf("\n");
}
