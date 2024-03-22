/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:50:44 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/21 15:22:30 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*death_count(void *param)
{
	t_dead				*philo;
	struct timeval		time;

	philo = (t_dead *)param;
    gettimeofday(&time, NULL);
	while ((time.tv_sec - philo->philo->time_eat.tv_sec) * 1000000 + time.tv_usec - philo->philo->time_eat.tv_usec < *philo->die)
	{
		gettimeofday(&time, NULL);
		usleep(100);	// SE EU ATIVAR ESSA PAUSA PARA POUPAR O USO DO PROCESSADOR PODE ACONTECER DO FILOSO NAO MORRER QUANDO O TEMPO PARA MORRER E IGUAL AO DE DORMIR
		if (philo->philo->repetitions == 0)	// ??????????????? philo->philo->repetitions > 0 ???????????????
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
		if (info->philo[i].dead)
			return (i + 1);
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
		if (info->philo[i].repetitions)
			return (1);
		i++;
	}
	return (0);
}

void    finish(t_info *info)
{
    int i;

	i = 0;
	while (i == 0 || repetitions(info))
	{
		i = dead_philosopher(info);
		if (i)
			printf("filoso %d morreu em %d ms\n", i, milliseconds(info));
		usleep(100);	// SE EU ATIVAR ESSA PAUSA PARA POUPAR O USO DO PROCESSADOR PODE ACONTECER DO FILOSO NAO MORRER QUANDO O TEMPO PARA MORRER E IGUAL AO DE DORMIR
	}
}
