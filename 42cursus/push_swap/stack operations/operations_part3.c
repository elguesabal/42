/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_part3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:00:42 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/01 18:38:16 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rra(t_stack **a, int print)
{
	t_stack	*remove;

	if (*a && (*a)->next)
	{
		remove = remove_last(a);
		insert_first(a, remove->n, remove->index);
		free(remove);
	}
	if (print)
		write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_stack **b, int print)
{
	t_stack	*remove;

	if (*b && (*b)->next)
	{
		remove = remove_last(b);
		insert_first(b, remove->n, remove->index);
		free(remove);
	}
	if (print)
		write(1, "rrb\n", 4);
	return (1);
}

int	rrr(t_stack **a, t_stack **b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print)
		write(1, "rrr\n", 4);
	return (1);
}
