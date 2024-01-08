/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:55:03 by joseanto          #+#    #+#             */
/*   Updated: 2024/01/08 09:35:47 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	message_received(int signum)
{
	static int	signals;
	static char	c;

	if (signum == SIGUSR2)
	{
		c = c << 1;
		c = c | 1;
	}
	else
		c = c << 1;
	signals++;
	if (signals == 8)
	{
		write(1, &c, 1);
		c = 0;
		signals = 0;
	}
}

int	main(void)
{
	struct sigaction	info;

	info.sa_handler = message_received;
	sigaction(SIGUSR1, &info, NULL);
	sigaction(SIGUSR2, &info, NULL);
	bat_signal();
	write(1, "\033[1;32m", 8);
	while (1)
		pause();
	return (0);
}
