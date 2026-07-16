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

	info_args(&info, argc, argv);
	if (info.help)
		help();
	resolve_host(&info);
	create_sockfd(&info);
	while (1)
	{
		build_icmp(&info);
		send_ping(&info);
		if (receive_ping(&info) == SUCCESS)
			parse_reply(&info);
		info.sequence++;
		sleep(1);
	}
	return (SUCCESS);
}
