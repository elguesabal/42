/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:46:45 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/12 15:54:25 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


// void	*simulation(void *param)	// AKI VAI GERAR AS ACOES DE UM FILOSOFO
// {
// 	int		i;
// 	t_info	*info;

// 	info = (t_info *)param;
// 	i = 0;
// 	while (!info->philo[i].dead)
// 	{
// 		pthread_create(&info->philo[i].id, NULL, simulation, &info);
// 		pthread_join(info->philo[i].id, NULL);
// 		i++;
// 	}
// 	return (NULL);
// }	info->slept

void	*action(void *param)
{
	t_info		*info;
	static int	actions;

	info = (t_info *)param;
	if (actions == 0)
	{
		pthread_mutex_lock(&info->forks[0].lock);
		printf("pegou um garfo em %d ms\n", milliseconds(info));
		pthread_mutex_unlock(&info->forks[0].lock);
		printf("pegou um garfo em %d ms\n", milliseconds(info));
		printf("comecou a comer em %d ms\n", milliseconds(info));
		usleep(info->eat);
		actions++;
	}
	else if (actions == 1)
	{
		printf("dormiu em %d ms\n", milliseconds(info));
		usleep(info->slept);
		actions++;
	}
	else if (actions == 2)
	{
		printf("pensou em %d ms\n", milliseconds(info));
		actions++;
	}

	if (actions == 2)
		actions = 0;

	return (NULL);
}

void	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n)
	{
		pthread_mutex_init(&info->forks[i].lock, NULL);
		i++;
	}
}

void	destroy_mutex(t_info *info)
{
	int	i;
	
	i = 0;
	while (i < info->n)
	{
		pthread_mutex_destroy(&info->forks[i].lock);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_info	info;
	int		i;

	if (verification(argc, argv))
		return (0);
	if (init_info(&info, argv))
		return (0);




	init_mutex(&info);

	i = 0;
	while (1)
	{
		pthread_create(&info.philo[0].id, NULL, action, &info);
		pthread_join(info.philo[0].id, NULL);
		i++;
	}

	destroy_mutex(&info);





	// i = 0;
	// printf("microssegundos die: %d", info.die);
	// while (i < info.n)
	// {
	// 	printf("filosofo: %d\n", info.philo[i].philo);
	// 	printf("garfo: %d\n\n", info.forks[i].fork);
	// 	i++;
	// }
	// printf("n: %d\ndie: %d\neat: %d\nslept: %d\n", info.n, info.die, info.eat, info.slept);
	// printf("segundos: %ld\tmicrossegundos: %ld\n", info.time.tv_sec, info.time.tv_usec);
	// printf("segundos corridos: %d", milliseconds(&info));

	free(info.philo);
	free(info.forks);
	return (0);
}