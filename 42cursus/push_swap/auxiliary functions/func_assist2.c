/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_assist2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:20:27 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/01 18:33:36 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	size_stack(t_stack **no)
{
	t_stack	*assist;
	int		size;

	assist = *no;
	size = 0;
	while(assist)
	{
		assist = assist->next;
		size++;
	}
	return (size);
}

int	stack_check(t_stack *list)
{
	t_stack	*assist_a;

	assist_a = list;
	while (assist_a->next != NULL)
	{
		if (assist_a->n > assist_a->next->n)
			return (0);
		assist_a = assist_a->next;
	}
	return (1);
}

void	print_stacks(t_stack **a, t_stack **b)
{
	t_stack	*assist_a;
	t_stack	*assist_b;

	assist_a = *a;
	assist_b = *b;
	write(1, "--------------------------------------------\n", 45);
	while (assist_a || assist_b)
	{
		if (assist_a)
		{
			ft_putnbr(assist_a->n);
			write(1, " ", 1);
		}
		else
			write(1, "  ", 2);
		if (assist_a)
			assist_a = assist_a->next;
		if (assist_b)
			ft_putnbr(assist_b->n);
		write(1, "\n", 1);
		if (assist_b)
			assist_b = assist_b->next;
	}
	write(1, "\n- -\na b\n\n", 10);
}
