/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:33:12 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/21 15:22:00 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	eat(t_info *info, int i)
{
	pthread_mutex_lock(&info->forks[i]);
	if (dead_philosopher(info) == 0)
	{
		printf("filoso %d pegou um garfo em %d ms\n", i + 1, milliseconds(info));
	}
	if (i + 1 == info->n)
	{
		pthread_mutex_lock(&info->forks[0]);
	}
	else
	{
		pthread_mutex_lock(&info->forks[i + 1]);
	}
	if (dead_philosopher(info) == 0)
	{
		gettimeofday(&info->philo[i].time_eat, NULL);
		printf("filoso %d pegou um garfo em %d ms\n", i + 1, milliseconds(info));
		printf("filoso %d comecou a comer em %d ms\n", i + 1, milliseconds(info));
		usleep(info->eat);
	}
	pthread_mutex_unlock(&info->forks[i]);
	if (i + 1 == info->n)
		pthread_mutex_unlock(&info->forks[0]);
	else
		pthread_mutex_unlock(&info->forks[i + 1]);
	info->philo[i].repetitions--;
// printf("\t\t\tfalta %d repeticoes para o filosofo %d\n", info->philo[i].repetitions, i + 1);
	info->philo[i].actions++;
}

void	to_sleep(t_info *info, int i)
{
    printf("filoso %d dormiu em %d ms\n", i + 1, milliseconds(info));
    usleep(info->slept);
    info->philo[i].actions++;
}

void	think(t_info *info, int i)
{
	printf("filoso %d pensou em %d ms\n", i + 1, milliseconds(info));
	info->philo[i].actions++;
}

void	*philosopher(void *param)
{
	t_info		*info;
	pthread_t	id;
	t_dead		philo;
	int			i;

	i = number();
	info = (t_info *)param;
	philo.philo = &info->philo[i];
	philo.die = &info->die;
	pthread_create(&id, NULL, death_count, &philo);
	while ((info->philo[i].repetitions < 0 && dead_philosopher(info) == 0) || (info->philo[i].repetitions > 0 && info->philo[i].dead == 0))
	{
		if (info->philo[i].actions == 0/* && dead_philosopher(info) == 0*/)
			eat(info, i);
		else if (info->philo[i].actions == 1/* && dead_philosopher(info) == 0*/)
			to_sleep(info, i);
		else if (info->philo[i].actions == 2/* && dead_philosopher(info) == 0*/)
			think(info, i);
		if (info->philo[i].actions == 3)
			info->philo[i].actions = 0;
	}
	pthread_join(id, NULL);
	return (NULL);
}

void	creat_philosopher(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n)
	{
		pthread_create(&info->philo[i].id, NULL, philosopher, info);
		pthread_detach(info->philo[i].id);
		usleep(100);
		i++;
	}
}
