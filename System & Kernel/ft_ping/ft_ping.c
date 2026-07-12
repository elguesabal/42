/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 16:30:06 by joseanto          #+#    #+#             */
/*   Updated: 2026/07/07 16:30:06 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int	main(int argc, char **argv)
{
	t_info	info;
	char	packet[ICMP_PACKET_SIZE];

	info_args(&info, argc, argv);
	if (info.help)
		help();
	resolve_host(&info);
	test_socket();
	build_icmp(packet, 1);
	return (SUCCESS);
}
