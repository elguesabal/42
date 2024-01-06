/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:55:06 by joseanto          #+#    #+#             */
/*   Updated: 2024/01/03 18:10:56 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == 43)
		str++;
	while (*str && *str > 47 && *str < 58)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}

void	send_message(int pid, char c)
{
	int	bit;
	
	bit = 7;
	while(bit >= 0)
	{
		if((c >> bit) & 1)
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

	if(argc == 3)
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while(argv[2][i])
		{
			send_message(pid, argv[2][i]);
			i++;
		}
	}
	else
		write(1, "Faz essa bagaca direito\n", 24);
	return (0);
}