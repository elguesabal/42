/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:21:35 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/01 18:46:15 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i--;
	}
	if (verification_part1(argc, argv, i) || verification_part2(argv, &a, i))
	{
		if (argc == 2)
			free_split(argv);
		return (!write(1, "Error\n", 6));
	}
	if (argc == 2)
		free_split(argv);
	index_list(&a);
	sort_list(&a, &b);
	free_list(&a);
	free_list(&b);
	return (0);
}
