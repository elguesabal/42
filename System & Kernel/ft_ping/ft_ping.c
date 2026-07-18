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

	signal(SIGINT, stop_ping);
	info_args(&info, argc, argv);
	if (info.help)
		help();
	resolve_host(&info);
	create_sockfd(&info);
	while (!stop_requested())
	{
		build_icmp(&info);
		send_ping(&info);
		if (receive_ping(&info) == SUCCESS)
		{
			update_statistics(&info);
			print_ping(&info);
		}
		info.sequence++;
		sleep(1);
	}
	print_statistics(&info);
	return (SUCCESS);
}
