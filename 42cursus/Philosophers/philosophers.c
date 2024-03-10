/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:46:45 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/08 11:47:24 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	alloc_forks(t_info *info, int n)
{
	int	i;

	info->philo = malloc((n + 1) * sizeof(t_philo));
	info->forks = malloc((n + 1) * sizeof(t_fork));
	if (!info->forks || !info->philo)
		return (error("Error\nmemoria nao alocada para os garfos ou filosofos\n"));
	i = 0;
	while (i < n)
	{
		info->philo[i].philo = i + 1;
		// info->philo[i].time_die = ;
		// info->philo[i].time_eat = ;
		// info->philo[i].time_sleep = ;
		info->forks[i].fork = i + 1;
		info->forks[i].available = 1;
		i++;
	}
	return (0);
}



int	verification(int argc, char **argv)
{
	if (argc < 5 || argc > 6) // ./philolosophers n morrer comer dormir [vzs]
		return (error("Error\nnumero de argumentos invalidos\n"));

	if (argv[1][0] == '\0' || argv[1][0] == '0' || is_number(argv[1]))
		return (error("Error\nnumero de filosofos invalido\n"));
	
	if (argv[2][0] == '\0' || argv[2][0] == '0' || is_number(argv[2]))
		return (error("Error\nnumero para morrer em ms invalido\n"));

	if (argv[3][0] == '\0' || argv[3][0] == '0' || is_number(argv[3]))
		return (error("Error\nnumero para comer em ms invalido\n"));

	if (argv[4][0] == '\0' || argv[4][0] == '0' || is_number(argv[4]))
		return (error("Error\nnumero para dormir em ms invalido\n"));

	if (argc == 6 && (argv[5][0] == '\0' || argv[5][0] == '0' || is_number(argv[5])))
		return (error("Error\nnumero de repeticoes invalido\n"));

	return (0);
}



int	main(int argc, char **argv)
{
	t_info	info;
	int		i;

	if (verification(argc, argv))	// VERIFICACOES
		return (0);
	info.n = ft_atoi(argv[1]);
	if (alloc_forks(&info, info.n))
		return (!error("Error\nmemoria nao alocada\n"));

	i = 0;
	while (i < info.n)
	{
		printf("filosofo: %d\n", info.philo[i].philo);
		printf("garfo: %d\n", info.forks[i].fork);
		printf("disponibilidade do garfo: %d\n\n", info.forks[i].available);
		i++;
	}

	free(info.philo);
	free(info.forks);
	return (0);
}