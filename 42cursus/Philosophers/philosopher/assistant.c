/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:50:44 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/26 08:26:11 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*death_count(void *param)
{
	t_dead			*philo;
	struct timeval	time;

	philo = (t_dead *)param;
	gettimeofday(&time, NULL);
	while ((time.tv_sec - philo->philo->time_eat.tv_sec) * 1000000
		+ time.tv_usec - philo->philo->time_eat.tv_usec < *philo->die)
	{
		gettimeofday(&time, NULL);
		usleep(100);
		if (philo->philo->repetitions == 0)
			return (NULL);
	}
	philo->philo->dead = 1;
	return (NULL);
}

int	dead_philosopher(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n)
	{
		if (info->philo[i].dead > 0)
		{
			if (info->philo[0].repetitions > -1)
				info->philo[i].dead = -1;
			return (i + 1);
		}
		i++;
	}
	return (0);
}

int	repetitions(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n)
	{
		if (info->philo[i].repetitions > 0)
			return (1);
		i++;
	}
	return (0);
}

int	all_dead(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n)
	{
		if (info->philo[i].dead == 0)
			return (0);
		i++;
	}
	return (1);
}

void	finish(t_info *info)
{
	int	i;

	i = 0;
	while (i == 0 || repetitions(info))
	{
		if (info->philo[0].repetitions < 0)
		{
			i = dead_philosopher(info);
			if (i)
				printf("%dms %d \033[0;31mdied\n\033[0m", milliseconds(info), i);
		}
		else if (info->philo[0].repetitions > -1)
		{
			i = dead_philosopher(info);
			if (i)
				printf("%dms %d \033[0;31mdied\n\033[0m", milliseconds(info), i);
			if (repetitions(info) == 0 || all_dead(info))
				return ;
		}
		usleep(100);
	}
}
