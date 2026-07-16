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
 * @brief VERIFICA SE O BUFFER RECEBIDO POR recvmsg FOI DESTINADO A ESTE PROGRAMA
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
 * @return RETORNA A MACRO SUCCESS SE A RESPOSTA FOR PARA ESTE PROGRAMA
 * @return RETORNA A MACRO ERROR SE A RESPOSTA NAO FOR PARA ESTE PROGRAMA
*/
int	validate_icmp(t_info *info)
{
	struct iphdr	*ip;
	struct icmphdr	*icmp;

	ip = (struct iphdr *)info->recv_buffer;
	icmp = (struct icmphdr *)(info->recv_buffer + (ip->ihl * 4));
	if (icmp->type != ICMP_ECHOREPLY)
		return (ERROR);
	if (ntohs(icmp->un.echo.id) != (getpid() & 0xFFFF))
		return (ERROR);
	if (ntohs(icmp->un.echo.sequence) != info->sequence)
		return (ERROR);
	return (SUCCESS);
}

/**
 * @author VAMPETA
 * @brief VERIFICA A QUANTIDADE DE BYTES DE recvmsg E IDENTIFICA ERROS
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
 * @param bytes NUMERO DE BYTES RETORNADOS POR recvmsg
 * @return RETORNA A MACRO SUCCESS SE A RESPOSTA FOR VALIDA E VERIFICADA
 * @return RETORNA A MACRO ERROR EM CASO DE TIMEOUT
 * @return RETORNA A MACRO WAIT CASO OS BYTES RECEBIDOS NAO FOREM DESTE PROGRAMA
*/
int	validate_bytes(t_info *info, ssize_t bytes)
{
	if (bytes < 0)
	{
		if (errno == EAGAIN || errno == EWOULDBLOCK)
		{
			info->lost_packets++;
			return (ERROR);
		}
		if (errno == EINTR)
		{
			// SIGNAL
		}
		fprintf(stderr, "ft_ping: recvmsg: %s\n", strerror(errno));
		exit(ERROR);
	}
	if (validate_icmp(info) == SUCCESS)
		return (SUCCESS);
	return (WAIT);
}

/**
 * @author VAMPETA
 * @brief RECEBE A RESPOSTA DE UM PING
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
 * @return RETORNA A MACRO SUCCESS SE A RESPOSTA FOR VALIDA E VERIFICADA
 * @return RETORNA A MACRO ERROR EM CASO DE TIMEOUT
*/
int	receive_ping(t_info *info)
{
	struct msghdr		msg;
	struct iovec		iov;
	struct sockaddr_in	from;
	int					result;

	memset(&msg, 0, sizeof(msg));
	iov.iov_base = info->recv_buffer;
	iov.iov_len = sizeof(info->recv_buffer);
	msg.msg_name = &from;
	msg.msg_namelen = sizeof(from);
	msg.msg_iov = &iov;
	msg.msg_iovlen = 1;
	while (1)
	{
		result = validate_bytes(info, recvmsg(info->sockfd, &msg, 0));
		if (result != WAIT)
			return (result);
	}
}

/**
 * @author VAMPETA
 * @brief INTERPRETA O BUFFER RECEBIDO POR recvmsg
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
*/
void	parse_reply(t_info *info)
{
	struct iphdr	*ip;
	struct icmphdr	*icmp;

	ip = (struct iphdr *)info->recv_buffer;
	icmp = (struct icmphdr *)(info->recv_buffer + (ip->ihl * 4));
	printf("TTL: %d\n", ip->ttl);
	printf("TYPE: %d\n", icmp->type);
	printf("CODE: %d\n", icmp->code);
	printf("ID: %d\n", ntohs(icmp->un.echo.id));
	printf("SEQ: %d\n", ntohs(icmp->un.echo.sequence));
printf("\n\n");
}
