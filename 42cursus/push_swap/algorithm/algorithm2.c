/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:17:44 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/01 18:32:11 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_tree(t_stack **stack_a)
{
	if (((*stack_a)->next->n > (*stack_a)->n)
		&& ((*stack_a)->next->n > (*stack_a)->next->next->n))
		rra(stack_a, 1);
	if (((*stack_a)->n > (*stack_a)->next->n)
		&& ((*stack_a)->n > (*stack_a)->next->next->n))
		ra(stack_a, 1);
	if ((*stack_a)->n > (*stack_a)->next->n
		&& (*stack_a)->n < (*stack_a)->next->next->n)
		sa(stack_a, 1);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int		count;
	t_stack	*n_small;

	count = 0;
	n_small = small_node(*stack_a);
	reposition_small_node(stack_a, n_small, count);
	pb(stack_a, stack_b, 1);
	sort_tree(stack_a);
	pa(stack_b, stack_a, 1);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		count;
	t_stack	*n_small;

	count = 0;
	n_small = small_node(*stack_a);
	reposition_small_node(stack_a, n_small, count);
	pb(stack_a, stack_b, 1);
	sort_four(stack_a, stack_b);
	pa(stack_b, stack_a, 1);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		max_bits;
	int		i;
	int		size_list;

	i = 0;
	max_bits = count_max_of_bits(index_max(*stack_a));
	while (i < max_bits)
	{
		size_list = size_stack(stack_a);
		while (size_list)
		{
			if ((((*stack_a)->index >> i) & 0b0000001) == 0)
				pb(stack_a, stack_b, 1);
			else
				ra(stack_a, 1);
			size_list--;
		}
		while (*stack_b != NULL)
			pa(stack_a, stack_b, 1);
		i++;
	}
}

void	sort_list(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_check(*stack_a))
		return ;
	if (size_stack(stack_a) == 2)
		sa(stack_a, 1);
	else if (size_stack(stack_a) == 3)
		sort_tree(stack_a);
	else if (size_stack(stack_a) == 4)
		sort_four(stack_a, stack_b);
	else if (size_stack(stack_a) == 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
