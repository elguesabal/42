/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:06:34 by joseanto          #+#    #+#             */
/*   Updated: 2026/07/15 19:06:34 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ping.h"

/**
 * @author VAMPETA
 * @brief ENVIA UM PING
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
 * @return RETORNA O NUMERO DE BYTES ENVIADOS
*/
ssize_t	send_ping(t_info *info)
{
	ssize_t	bytes;

	gettimeofday(&info->send_time, NULL);
	info->transmitted++;
	bytes = sendto(
			info->sockfd,
			info->packet,
			ICMP_PACKET_SIZE,
			0,
			(struct sockaddr *)&info->addr,
			sizeof(info->addr)
			);
	if (bytes < 0)
	{
		fprintf(stderr, "ft_ping: sendto: %s\n", strerror(errno));
		exit(ERROR);
	}
	return (bytes);
}
