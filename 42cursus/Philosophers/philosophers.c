/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:46:45 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/11 19:47:50 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"




void	*simulation(void *param)	// AKI VAI GERAR AS ACOES DE UM FILOSOFO
{
	int		i;
	t_info	*info;

	info = (t_info *)param;
	i = 0;
	while (!info->philo[i].dead)
	{
		pthread_create(&info->philo[i].id, NULL, simulation, &info);
		pthread_join(info->philo[i].id, NULL);
		i++;
	}
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



// simulation(&info);	// AKI DEVO CHAMAR UMA VEZ PRA CADA FILOSOFO
	i = 0;
	while (i < info.n)
	{
		pthread_create(&info.philo[i].id, NULL, simulation, &info);
		pthread_detach(info.philo[i].id);
		i++;
	}



	// i = 0;
	// printf("microssegundos die: %d", info.die);
	// while (i < info.n)
	// {
	// 	printf("filosofo: %d\n", info.philo[i].philo);
	// 	printf("garfo: %d\n\n", info.forks[i].fork);
	// 	i++;
	// }
	// printf("n: %d\ndie: %d\neat: %d\nslept: %d\n", info.n, info.die, info.eat, info.slept);

	free(info.philo);
	free(info.forks);
	return (0);
}