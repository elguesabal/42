/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:46:45 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/15 14:08:25 by joseanto         ###   ########.fr       */
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
			return (i + 1);
		i++;
	}
	return (0);
}





void	*death_count(void *param)	//	PARECE Q O FILOSOFO TA MORRENDO PQ TO PASSANDO UM VALOR E NAO CONSIGO MODIFICA-LO EM OUTRA FUNCAO PQ NAO E UM PONTEIRO
{
	t_dead				*philo;
	struct timeval		time;

	philo = (t_dead *)param;


	// ESSE CODIGO TAVA BUGADO
	// while (philo->philo->dead)
	// {
	// 	gettimeofday(&time, NULL);
	// 	if ((time.tv_sec - philo->philo->time_eat.tv_sec) * 1000000 + time.tv_usec - philo->philo->time_eat.tv_usec >= philo->die)
	// 	{
	// 		philo->philo->dead = 1;
	// 		return (0);
	// 	} 
	// 	usleep(100);
	// }


	// MAS ESSE NAO KKKKK	ELE TAVA BUGADO TBM KKKKKKKKKKKKK	MAS O BUG NAO ERA AKI MAS NO STRUCT PASSADO POR ELE KKKK
	while ((time.tv_sec - philo->philo->time_eat.tv_sec) * 1000000 + time.tv_usec - philo->philo->time_eat.tv_usec < *philo->die)
	{
		gettimeofday(&time, NULL);
		usleep(100);
	}
	philo->philo->dead = 1;

	return (0);
}

void	action(t_info *info, int i)
{
	pthread_t	id;
	t_dead		philo;
	// struct timeval	time;	//	AKI EU TENHO Q ARMAZENAAR O TEMPPO DA ULTIMA VEZ Q O FILOSOFO COMEU

	philo.philo = &info->philo[i];
	philo.die = &info->die;
	philo.dead = &info->philo[i].dead;
	pthread_create(&id, NULL, death_count, &philo);
	pthread_detach(id);

	while (dead_philosopher(info) == 0)
	{
		if (info->philo[i].actions == 0 && dead_philosopher(info) == 0)
		{
			pthread_mutex_lock(&info->forks[i].lock);
			if (dead_philosopher(info) == 0)
			{
				printf("filoso %d pegou um garfo em %d ms\n", i + 1, milliseconds(info));
				// info->philo[i].left = &info->forks[i];	// ACHEI Q IA PRECISAR SALVAR O PONTEIRO
			}
			if (i + 1 == info->n)
			{
				pthread_mutex_lock(&info->forks[0].lock);
				// info->philo[i].right = &info->forks[0];	// ACHEI Q IA PRECISAR SALVAR O PONTEIRO
			}
			else
			{
				pthread_mutex_lock(&info->forks[i + 1].lock);
				// info->philo[i].right = &info->forks[i + 1];	// ACHEI Q IA PRECISAR SALVAR O PONTEIRO
			}
			if (dead_philosopher(info) == 0)
			{
				printf("filoso %d pegou um garfo em %d ms\n", i + 1, milliseconds(info));
				printf("filoso %d comecou a comer em %d ms\n", i + 1, milliseconds(info));
			}
			gettimeofday(&info->philo[i].time_eat, NULL);
			usleep(info->eat);
			gettimeofday(&info->philo[i].time_eat, NULL);
			pthread_mutex_unlock(&info->forks[i].lock);
			// info->philo[i].left = NULL;	// ACHEI Q IA PRECISAR SALVAR O PONTEIRO
			if (i + 1 == info->n)
				pthread_mutex_unlock(&info->forks[0].lock);
			else
				pthread_mutex_unlock(&info->forks[i + 1].lock);
			// info->philo[i].right = NULL;	// ACHEI Q IA PRECISAR SALVAR O PONTEIRO
			info->philo[i].actions++;
		}
		else if (info->philo[i].actions == 1 && dead_philosopher(info) == 0)
		{
			printf("filoso %d dormiu em %d ms\n", i + 1, milliseconds(info));
			usleep(info->slept);
			info->philo[i].actions++;
		}
		else if (info->philo[i].actions == 2 && dead_philosopher(info) == 0)
		{
			printf("filoso %d pensou em %d ms\n", i + 1, milliseconds(info));
			info->philo[i].actions++;
		}

		if (info->philo[i].actions == 3)
			info->philo[i].actions = 0;
	}
}

int	number()
{
	static int	i;
	return (i++);
}

void	*philosophers(void *param)
{
	t_info		*info;

	info = (t_info *)param;
	action(info, number());
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
		// info.i = i;
		pthread_create(&info.philo[i].id, NULL, philosophers, &info);
		// pthread_join(info.philo[i].id, NULL);
		pthread_detach(info.philo[i].id);	// AKI PODE SER SUBSTITUIDO POR FUNCOES pthread_join() APOS O LOOP Q PROCURA A MORTE DE UM FILOSOSO SENDO Q ANTES PODE TER UM LOOP MATANDO TODOS OS FILOSOFOS
		usleep(100);	// ISSO GARANTE Q info.i NAO VAI SER MODIFICADO ANTES DE SER SALVO DENTRO DA FUNCAO philosophers()	// NAO TA FUNCIONANDO

		// if (i + 1 == info.n)
		// 	i = 0;
		// else
		// 	i++;
		i++;
	}

// usleep(5000000);
// info.philo[0].dead = 1;	// ASSASSINEI UM FILOSO PARA VER O RESULTADO DO VALGRIND



	// i = 1;
	// while (i)
	// {
	// 	if (dead_philosopher(&info))
	// 	{
	// 		printf("filoso %d morreu em %d ms\n", i + 1, milliseconds(&info));
	// 		i = 0;	// MENTIRA Q EU FIZ ISSO KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK SEMPRE SERA O FILOSO 2 Q VAI SER ANUNCIADO COMO MORTO
	// 	}
	// 	usleep(500);	// LOOP INFINITO USANDO usleep() PARA NAO FORCAR O PC
	// }

	i = 0;
	while (i == 0)
	{
		i = dead_philosopher(&info);
		if (i)
			printf("filoso %d morreu em %d ms\n", i + 1, milliseconds(&info));
		usleep(500);
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