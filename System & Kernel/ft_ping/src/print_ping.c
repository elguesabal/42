/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:31:35 by joseanto          #+#    #+#             */
/*   Updated: 2026/07/18 18:31:35 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ping.h"

/**
 * @author VAMPETA
 * @brief CALCULA O TEMPO DO PING
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
*/
double	get_rtt(t_info *info)
{
	double	rtt;

	rtt = (info->receive_time.tv_sec - info->send_time.tv_sec) * 1000.0;
	rtt += (info->receive_time.tv_usec - info->send_time.tv_usec) / 1000.0;
	return (rtt);
}

/**
 * @author VAMPETA
 * @brief INTERPRETA O BUFFER RECEBIDO POR recvmsg E PRINTA INFORMACOES DO PING
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
*/
void	print_ping(t_info *info)
{
	printf("%i bytes from %s: ", ICMP_PACKET_SIZE, info->ip);
	printf("icmp_seq=%i ", ntohs(info->recv_icmp->un.echo.sequence));
	printf("ttl=%i ", info->recv_ip->ttl);
	printf("time=%.3f ms\n", get_rtt(info));
}
