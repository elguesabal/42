/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:00:39 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/01 13:01:24 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(Stack **a, Stack **b)
{
	Stack	*remove;

	if(*a)
	{
		remove = remove_first(a);
		insert_first(b, remove->n);
		free(remove);
	}
}

void	ra(Stack **a)
{
	Stack	*remove;

	if(*a && (*a)->next)
	{
		remove = remove_first(a);
		insert_last(a, remove->n);
		free(remove);
	}
}

void	rb(Stack **b)
{
	Stack	*remove;

	if(*b && (*b)->next)
	{
		remove = remove_first(b);
		insert_last(b, remove->n);
		free(remove);
	}
}

void	rr(Stack **a, Stack **b)
{
	ra(a);
	rb(b);
}

