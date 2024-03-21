/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:33:41 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/21 14:40:35 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	is_number(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

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

int	init_info(t_info *info, char **argv)
{
	int	i;

	info->n = ft_atoi(argv[1]);
	info->die = ft_atoi(argv[2]) * 1000;
	info->eat = ft_atoi(argv[3]) * 1000;
	info->slept = ft_atoi(argv[4]) * 1000;
	gettimeofday(&info->time, NULL);
	info->philo = malloc(info->n * sizeof(t_philo));
	info->forks = malloc(info->n * sizeof(pthread_mutex_t));
	if (!info->forks || !info->philo)
		return (printf("Error\nMemoria nao alocada corretamente\n"));
	i = 0;
	while (i < info->n)
	{
		info->philo[i].dead = 0;
		if (argv[5])
			info->philo[i].repetitions = ft_atoi(argv[5]);
		else
			info->philo[i].repetitions = -1;
		info->philo[i].actions = 0;
		info->philo[i].time_eat = info->time;
		pthread_mutex_init(&info->forks[i], NULL);
		i++;
	}
	return (0);
}

int	number(void)
{
	static int	i = 0;

	return (i++);
}

int	milliseconds(t_info *info)
{
	struct timeval	current_time;
	int				seconds;
	int				microseconds;

	gettimeofday(&current_time, NULL);
	seconds = (current_time.tv_sec - info->time.tv_sec) * 1000;
	microseconds = (current_time.tv_usec - info->time.tv_usec) / 1000;
	return (seconds + microseconds);
}
