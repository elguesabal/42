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
 * @brief PRINTA ERROS DO MODO VERBOSE
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
*/
void	error_verbose(t_info *info)
{
	(void)info;
}

/**
 * @author VAMPETA
 * @brief VERIFICA SE O BUFFER RECEBIDO POR recvmsg FOI DESTINADO A ESTE PROGRAMA
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
 * @param icmp INFORMACOES DA FUNCAO recvmsg
 * @return RETORNA A MACRO WAIT SE A RESPOSTA NAO FOR OQUE ESTE PROGRAMA ESPERA
 * @return RETORNA A MACRO ERROR SE NAO FOR NENHUMA CASO ACIMA
*/
int	is_our_echo(t_info *info, struct icmphdr *icmp)
{
	if (ntohs(icmp->un.echo.id) != info->pid)
		return (WAIT);
	if (ntohs(icmp->un.echo.sequence) != info->sequence)
		return (WAIT);
	return (ERROR);
}

/**
 * @author VAMPETA
 * @brief VERIFICA SE O BUFFER RECEBIDO POR recvmsg FOI DESTINADO A ESTE PROGRAMA
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
 * @return RETORNA A MACRO SUCCESS SE A RESPOSTA FOR PARA ESTE PROGRAMA
 * @return RETORNA A MACRO ERROR SE A RESPOSTA NAO FOR PARA ESTE PROGRAMA
*/
int	validate_icmp(t_info *info)
{
	struct iphdr	*inner_ip;
	struct icmphdr	*inner_icmp;

	if (info->recv_icmp->type == ICMP_ECHOREPLY)
	{
		if (is_our_echo(info, info->recv_icmp) == WAIT)
			return (WAIT);
		return (SUCCESS);
	}
	if (info->recv_icmp->type == ICMP_DEST_UNREACH
		|| info->recv_icmp->type == ICMP_TIME_EXCEEDED
		|| info->recv_icmp->type == ICMP_PARAMETERPROB)
	{
		inner_ip = (struct iphdr *)(info->recv_buffer
				+ (info->recv_ip->ihl * 4)
				+ sizeof(struct icmphdr));
		inner_icmp = (struct icmphdr *)((char *)inner_ip + (inner_ip->ihl * 4));
		if (is_our_echo(info, inner_icmp) == WAIT)
			return (WAIT);
		if (info->verbose)
			error_verbose(info);
		return (ERROR);
	}
	return (WAIT);
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
	int	result;

	if (bytes < 0)
	{
		if (errno == EAGAIN || errno == EWOULDBLOCK)
		{
			info->lost_packets++;
			return (ERROR);
		}
		if (errno == EINTR)
			return (ERROR);
		fprintf(stderr, "ft_ping: recvmsg: %s\n", strerror(errno));
		exit(ERROR);
	}
	if (bytes < (ssize_t) sizeof(struct iphdr))
		return (WAIT);
	info->recv_ip = (struct iphdr *)info->recv_buffer;
	if (bytes < (ssize_t)((info->recv_ip->ihl * 4) + sizeof(struct icmphdr)))
		return (WAIT);
	info->recv_icmp = (struct icmphdr *)(info->recv_buffer
			+ (info->recv_ip->ihl * 4));
	result = validate_icmp(info);
	if (result == SUCCESS || result == ERROR)
		return (result);
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
		{
			if (result == SUCCESS)
				gettimeofday(&info->receive_time, NULL);
			return (result);
		}
	}
}
