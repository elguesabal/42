/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   icmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 17:49:59 by joseanto          #+#    #+#             */
/*   Updated: 2026/07/14 18:01:46 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ping.h"

void	build_icmp(t_info *info, unsigned int sequence)
{
	struct icmphdr	*icmp;
	char			*payload;

	icmp = (struct icmphdr *)info->packet;
	memset(icmp, 0, sizeof(*icmp));
	icmp->type = ICMP_ECHO;
	icmp->code = 0;
	icmp->checksum = 0;
	icmp->un.echo.id = htons(getpid());
	icmp->un.echo.sequence = htons(sequence);
	payload = info->packet + sizeof(struct icmphdr);
	memset(payload, 'A', ICMP_PAYLOAD_SIZE);
	icmp->checksum = checksum(info->packet, ICMP_PACKET_SIZE);
}
