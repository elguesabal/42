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











// int	last_death(t_info *info, int list)
// {
// 	int	i;

// 	i = 0;
// 	while (i < info->n)
// 	{
// 		list[i] = 0;
// 		i++;
// 	}

// 	i = 0;
// 	while (i < info->n)
// 	{
// 		printf("Teste: %d\n", list[i]);
// 		i++;
// 	}
// 	return (0);
// }









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
	// int	*list;	// ACHO Q VOU POR ESSA VARIAVEL DENTRO DE info

	// list = malloc(info->n * sizeof(int));	// NAO FIZ VERIFICACAO
	i = 0;
	while (i == 0 || repetitions(info))
	{
		if (info->philo[0].repetitions < 0)
		{
			i = dead_philosopher(info);
			if (i)
				printf("filoso %d morreu em %d ms\n", i, milliseconds(info));
		}
		else if (info->philo[0].repetitions > -1 /*&& repetitions(info)*/)
		{
			// i = last_death(info, list);	// TO COM DIFICULDADE DE SABER QUAL FOI O ULTIMO FILOSO A MORRER
			// if (i)
			// {
			// 	printf("filoso %d morreu em %d ms\n", i, milliseconds(info));
			// 	i = 0;
			// }
			if (repetitions(info) == 0 || all_dead(info))
			{
				// free(list);
				return ;
			}
		}
		usleep(100);	// SE EU ATIVAR ESSA PAUSA PARA POUPAR O USO DO PROCESSADOR PODE ACONTECER DO FILOSO NAO MORRER QUANDO O TEMPO PARA MORRER E IGUAL AO DE DORMIR
	}
}