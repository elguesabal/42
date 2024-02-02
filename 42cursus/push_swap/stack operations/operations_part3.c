/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:00:42 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/02 15:06:58 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rra(Stack **a, int print)
{
	Stack	*remove;

	if(*a && (*a)->next)
	{
		remove = remove_last(a);
		insert_first(a, remove->n);
		free(remove);
	}
	if(print)
		write(1, "rra\n", 4);
	return (1);
}

int	rrb(Stack **b, int print)
{
	Stack	*remove;

	if(*b && (*b)->next)
	{
		remove = remove_last(b);
		insert_first(b, remove->n);
		free(remove);
	}
	if(print)
		write(1, "rrb\n", 4);
	return (1);
}

int	rrr(Stack **a, Stack **b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if(print)
		write(1, "rrr\n", 4);
	return (1);
}