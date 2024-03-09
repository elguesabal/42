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

void	*alloc_forks(int n)
{
	int	*forks;
	int	i;

	forks = malloc((n + 1) * sizeof(int));
	if (!forks)
	{
		printf("erro\n");
		return (0);
	}
	i = 0;
	while (i < n)
	{
		forks[i] = i + 1;
		i++;
	}
	forks[n] = -1;
	return (forks);
}

int	main(int argc, char **argv)
{
	int	*forks;
	int	i;

	(void)argc;
	if (argc == 1 || argv[1][0] == '0')
	{
		printf("erro\n");
		return (0);
	}
	forks = alloc_forks(ft_atoi(argv[1]));

	i = 0;
	while (forks[i] != -1)
	{
		printf("teste: %d\n", forks[i]);
		i++;
	}

	free(forks);
	return (0);
}