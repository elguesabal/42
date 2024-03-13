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
// }






void	action(t_info *info, int i)
{
	static int	actions;	// AKI TA SALVANDO O VALOR INCREMENTADO POR OUTRAS THREADS

	if (actions == 0)
	{
		pthread_mutex_lock(&info->forks[i].lock);
		printf("filoso %d pegou um garfo em %d ms\n", i + 1, milliseconds(info));
		if (i + 1 == info->n)
			pthread_mutex_lock(&info->forks[0].lock);
		else
			pthread_mutex_lock(&info->forks[i + 1].lock);
		printf("filoso %d pegou um garfo em %d ms\n", i + 1, milliseconds(info));
		printf("filoso %d comecou a comer em %d ms\n", i + 1, milliseconds(info));
		usleep(info->eat);
		pthread_mutex_unlock(&info->forks[i].lock);
		if (i + 1 == info->n)
			pthread_mutex_unlock(&info->forks[0].lock);
		else
			pthread_mutex_unlock(&info->forks[i + 1].lock);
		actions++;
	}
	else if (actions == 1)
	{
		printf("filoso %d dormiu em %d ms\n", i + 1, milliseconds(info));
		usleep(info->slept);
		actions++;
	}
	else if (actions == 2)
	{
		printf("filoso %d pensou em %d ms\n", i + 1, milliseconds(info));
		actions++;
	}

	if (actions == 3)
		actions = 0;
}

void	*philosophers(void *param)
{
	t_info		*info;
	static int	i;

	info = (t_info *)param;
	while (!info->philo[i].dead)
	{
		// pthread_create(&info.philo[0].id, NULL, action, &info);
		// pthread_join(info.philo[0].id, NULL);
		action(info, i);


		i++;
		if (i == info->n)
			i = 0;
	}

	if (info->philo[0].dead)
		printf("filoso %d o filosofo morreu em %d ms\n", i + 1, milliseconds(info));

	return (NULL);
}



int	dead_philosopher(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n)
	{
		if (info->philo[i].dead)
			return (0);
		i++;
	}
	return (1);
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
	while (i < info.n)
	{
		pthread_create(&info.philo[i].id, NULL, philosophers, &info);
		// pthread_join(info.philo[i].id, NULL);
		pthread_detach(info.philo[i].id);

		// if (i + 1 == info.n)
		// 	i = 0;
		// else
		// 	i++;
		i++;
	}

// sleep(10);
// info.philo[0].dead++;	// ASSASSINEI UM FILOSO PARA VER O RESULTADO DO VALGRIND

	while (dead_philosopher(&info))
	{
		// LOOP INFINITO MAIS DPS EU POSSO POR UM usleep() PARA NAO FORCAR O PC
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