/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:55:06 by joseanto          #+#    #+#             */
/*   Updated: 2024/01/08 09:37:03 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str)
{
	int	result;

	result = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	while (*str && *str > 47 && *str < 58)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result);
}

static void	send_message(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit--;
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc == 3 && argv[2])
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i])
		{
			send_message(pid, argv[2][i]);
			i++;
		}
		write(1, "\033[1;32mBat-sinal enviado!\033[0m\n", 31);
	}
	else
		write(1, "\033[1;31mAcabou a bat-energia...\033[0m\n", 36);
	return (0);
}
