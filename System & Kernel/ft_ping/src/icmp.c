/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   icmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 17:49:59 by joseanto          #+#    #+#             */
/*   Updated: 2026/07/15 19:54:56 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ping.h"

/**
 * @author VAMPETA
 * @brief MONTA O CONTEUDO DE UM PING
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
*/
void	build_icmp(t_info *info)
{
	struct icmphdr	*icmp;
	char			*payload;

	icmp = (struct icmphdr *)info->packet;
	memset(icmp, 0, sizeof(*icmp));
	icmp->type = ICMP_ECHO;
	icmp->code = 0;
	icmp->checksum = 0;
	icmp->un.echo.id = htons(info->pid);
	icmp->un.echo.sequence = htons(info->sequence);
	payload = info->packet + sizeof(struct icmphdr);
	memset(payload, 'A', ICMP_PAYLOAD_SIZE);
	icmp->checksum = checksum(info->packet, ICMP_PACKET_SIZE);
}
