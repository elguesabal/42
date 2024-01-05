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

#include "minital.h"

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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	bit(int signum)
{
	// static char c;

	// if()
	// {
		
	// }
	// else
	// {
		
	// }
	// c++;
}

int	main(void)
{
	signal(SIGUSR1, bit);
	signal(SIGUSR2, bit);

	putnbr(getpid());
	write(1, "\n\n", 2);

	while(1)
	{
		pause();
	}
	return (0);
}