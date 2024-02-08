/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:00:35 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/06 10:43:50 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sa(Stack **a, int print)
{
	Stack	*remove;

	if (*a && (*a)->next)
	{
		remove = remove_second(a);
		insert_first(a, remove->n);
		free(remove);
	}
	if (print)
		write(1, "sa\n", 3);
	return (1);
}

int	sb(Stack **b, int print)
{
	Stack	*remove;

	if (*b && (*b)->next)
	{
		remove = remove_second(b);
		insert_first(b, remove->n);
		free(remove);
	}
	if (print)
		write(1, "sb\n", 3);
	return (1);
}

int	ss(Stack **a, Stack **b, int print)
{
	sa(a, 0);
	sb(b, 0);
	if (print)
		write(1, "ss\n", 3);
	return (1);
}

int	pa(Stack **a, Stack **b, int print)
{
	Stack	*remove;

	if (*b)
	{
		remove = remove_first(b);
		insert_first(a, remove->n);
		free(remove);
	}
	if (print)
		write(1, "pa\n", 3);
	return (1);
}
