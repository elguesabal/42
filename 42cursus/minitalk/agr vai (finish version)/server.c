/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:55:03 by joseanto          #+#    #+#             */
/*   Updated: 2024/01/03 17:50:14 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void putnbr(unsigned int n)
{
	if (n > 9)
	{
		putnbr(n / 10);
		putnbr(n % 10);
	}
	else
	{
		n += 48;
		write(1, &n, 1);
	}
}

void	message_received(int signum)
{
	static int	signals;
	static char	c;

	if(signum == SIGUSR2)
	{
		c = c << 1;
		c = c | 1;
	}
	else
		c = c << 1;
	signals++;
	if(signals == 8)
	{
		write(1, &c, 1);
		c = 0;
		signals = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, message_received);
	signal(SIGUSR2, message_received);

	write(1, "PID: ", 5);
	putnbr(getpid());
	write(1, "\n\n", 2);

	while(1)
	{
		pause();
	}
	return (0);
}