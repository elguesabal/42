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

int	dead_philosopher(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n)
	{

		if (info->philo[i].dead)
		{
			printf("filoso %d o filosofo morreu em %d ms\n", i + 1, milliseconds(info));
			return (0);
		}
		i++;
	}
	return (1);
}

// int	time_dead(t_info *info, int i)
// {
// 	info->philo[].dead = 1;
// 	usleep(milliseconds(info.philo[].));
// 	if ()
// 	return (0);
// }



void	action(t_info *info, int i)
{
	// static int	actions;	// AKI TA SALVANDO O VALOR INCREMENTADO POR OUTRAS THREADS

	while (!info->philo[i].dead)
	{
		if (info->philo[i].actions == 0)
		{
			// pthread_create();//
			// pthread_join();//
			pthread_mutex_lock(&info->forks[i].lock);
			printf("filoso %d pegou um garfo em %d ms\n", i + 1, milliseconds(info));
			if (i + 1 == info->n)
				pthread_mutex_lock(&info->forks[0].lock);
			else
				pthread_mutex_lock(&info->forks[i + 1].lock);
			printf("filoso %d pegou um garfo em %d ms\n", i + 1, milliseconds(info));
			printf("filoso %d comecou a comer em %d ms\n", i + 1, milliseconds(info));
			// if (time_dead(info))
			// {
			// 	info->philo[i].dead = 0;
			// }
			usleep(info->eat);
			pthread_mutex_unlock(&info->forks[i].lock);
			if (i + 1 == info->n)
				pthread_mutex_unlock(&info->forks[0].lock);
			else
				pthread_mutex_unlock(&info->forks[i + 1].lock);
			info->philo[i].actions++;
		}
		else if (info->philo[i].actions == 1)
		{
			printf("filoso %d dormiu em %d ms\n", i + 1, milliseconds(info));
			usleep(info->slept);
			info->philo[i].actions++;
		}
		else if (info->philo[i].actions == 2)
		{
			printf("filoso %d pensou em %d ms\n", i + 1, milliseconds(info));
			info->philo[i].actions++;
		}

		if (info->philo[i].actions == 3)
			info->philo[i].actions = 0;
	}
}

void	*philosophers(void *param)
{
	t_info		*info;
	// static int	i;	// TODA VEZ Q ESSA FUNCAO E CHAMADA PELA pthread_creat() ELA ASSUME O VALOR DE 0
	int			i;

	info = (t_info *)param;
	i = info->i;
	// while (!info->philo[i].dead)
	// {
		// pthread_create(&info.philo[0].id, NULL, action, &info);
		// pthread_join(info.philo[0].id, NULL);
		action(info, i);


		// i++;
	// 	if (i == info->n)
	// 		i = 0;
	// }

	// if (info->philo[0].dead)
	// 	printf("filoso %d o filosofo morreu em %d ms\n", i + 1, milliseconds(info));

	return (NULL);
}

int	main(int argc, char **argv)
{
	t_info	info;
	int		i;

	if (verification(argc, argv))
		return (0);
	if (init_info(&info, argv))
		return (0);



// printf("%ld\t%ld\n", info.time.tv_sec, info.time.tv_usec);
// printf("%ld\t%ld\n", info.philo[0].time_eat.tv_sec, info.philo[0].time_eat.tv_usec);
	// init_mutex(&info);	// JA TA INICIANDO NA FUNCAO init_info()

	i = 0;
	while (i < info.n)
	{
		info.i = i;
		pthread_create(&info.philo[i].id, NULL, philosophers, &info);
		// pthread_join(info.philo[i].id, NULL);
		pthread_detach(info.philo[i].id);
		usleep(100);	// ISSO GARANTE Q info.i NAO VAI SER MODIFICADO ANTES DE SER SALVO DENTRO DA FUNCAO philosophers()	// NAO TA FUNCIONANDO

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
		usleep(500);	// LOOP INFINITO USANDO usleep() PARA NAO FORCAR O PC
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