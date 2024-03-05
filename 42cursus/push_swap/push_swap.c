/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:21:35 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/05 16:01:05 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (argc == 1 || argv[1][0] == '\0')
		return (0);
	a = NULL;
	b = NULL;
	i = 1;
	if (argc == 2 && i--)
		argv = ft_split(argv[1], ' ');
	if (verification_part1(argv, i) || verification_part2(argv, &a, i))
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
	return (0);
}
