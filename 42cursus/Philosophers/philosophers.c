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

int	main(int argc, char **argv)
{
	int	n_philosophers = atoi(argv[1]); //
	int	time_death = atoi(argv[2]);
	int	time_eat = atoi(argv[3]);
	int	time_sleep = atoi(argv[4]);

	(void)argc;
	printf("filososfos: %d\n", n_philosophers);
	printf("morte: %d\n", time_death);
	printf("comer: %d\n", time_eat);
	printf("dormir: %d\n", time_sleep);
	return (0);
}