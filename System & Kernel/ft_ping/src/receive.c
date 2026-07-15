/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:31:35 by joseanto          #+#    #+#             */
/*   Updated: 2026/07/15 18:31:35 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ping.h"

/**
 * @author VAMPETA
 * @brief RECEBE A RESPOSTA DE UM PING
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
 * @return RETORNA O NUMERO DE BYTES RECEBIDOS POR recvmsg
*/
ssize_t	receive_ping(t_info *info)
{
	struct msghdr		msg;
	struct iovec		iov;
	struct sockaddr_in	from;
	ssize_t				bytes;

	memset(&msg, 0, sizeof(msg));
	iov.iov_base = info->recv_buffer;
	iov.iov_len = sizeof(info->recv_buffer);
	msg.msg_name = &from;
	msg.msg_namelen = sizeof(from);
	msg.msg_iov = &iov;
	msg.msg_iovlen = 1;
	bytes = recvmsg(info->sockfd, &msg, 0);
	return (bytes);
}

/**
 * @author VAMPETA
 * @brief INTERPRETA O BUFFER RECEBIDO POR recvmsg
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
*/
void	parse_reply(t_info *info)
{
	struct iphdr	*ip;

	ip = (struct iphdr *)info->recv_buffer;
	printf("TTL: %d\n", ip->ttl);
}




	// if (bytes < 0)
	// {
	// 	if (errno == EAGAIN || errno == EWOULDBLOCK)
	// 	{
	// 		// info->lost_packets++;
	// 		return (-1);
	// 	}
	// 	fprintf(stderr, "ft_ping: recvmsg: %s\n", strerror(errno));
	// 	exit(ERROR);
	// }