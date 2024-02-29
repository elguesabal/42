/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:00:39 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/29 19:15:55 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pb(Stack **a, Stack **b, int print)
{
	Stack	*remove;

	if (*a)
	{
		remove = remove_first(a);
		insert_first(b, remove->n, remove->index);
		free(remove);
	}
	if (print)
		write(1, "pb\n", 3);
	return (1);
}

int	ra(Stack **a, int print)
{
	Stack	*remove;

	if (*a && (*a)->next)
	{
		remove = remove_first(a);
		insert_last(a, remove->n, remove->index);
		free(remove);
	}
	if (print)
		write(1, "ra\n", 3);
	return (1);
}

int	rb(Stack **b, int print)
{
	Stack	*remove;

	if (*b && (*b)->next)
	{
		remove = remove_first(b);
		insert_last(b, remove->n, remove->index);
		free(remove);
	}
	if (print)
		write(1, "rb\n", 3);
	return (1);
}

int	rr(Stack **a, Stack **b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
		write(1, "rr\n", 3);
	return (1);
}
