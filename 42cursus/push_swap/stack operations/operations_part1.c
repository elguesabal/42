/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:00:35 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/01 11:41:08 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(Stack **a)
{
	Stack	*remove;

	if(*a && (*a)->next)
	{
		remove = remove_second(a);
		insert_first(a, remove->n);
		free(remove);
	}
}

void	sb(Stack **b)
{
	Stack	*remove;

	if(*b && (*b)->next)
	{
		remove = remove_second(b);
		insert_first(b, remove->n);
		free(remove);
	}
}

void	ss(Stack **a, Stack **b)
{
	sa(a);
	sb(b);
}

void	pa(Stack **a, Stack **b)
{
	Stack	*remove;

	if(*b)
	{
		remove = remove_first(b);
		insert_first(a, remove->n);
		free(remove);
	}
}
