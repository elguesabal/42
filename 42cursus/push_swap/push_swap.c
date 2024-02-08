/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:21:35 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/08 16:10:56 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_check(Stack **a, Stack **b)
{
	Stack	*assist_a;

	if (!*a || *b)
		return (1);
	assist_a = (*a)->next;
	while (assist_a)
	{
		if (assist_a->previous->n > assist_a->n)
			return (1);
		assist_a = assist_a->next;
	}
	return (0);
}

static void	operator_algorithm(Stack **a, Stack **b, int print)
{
	while (stack_check(a, b))
	{
		if (bigger_than_next(a) && smaller_than_next(b) && ss(a, b, 1));
		else if (bigger_than_next(a) && sa(a, 1));
		else if (smaller_than_next(b) && sb(b, 1));
		else if (*a && first_biggest_last(a) && *b && first_smallest_last(b) && rr(a, b, 1));
		else if (*a && first_biggest_last(a) && ra(a, 1));
		else if (*b && first_smallest_last(b) && rb(b, 1));
		else if (*a && first_biggest_last(a) && *b && first_smallest_last(b) && rrr(a, b, 1));
		else if (*a && first_biggest_last(a) && rra(a, 1));
		else if (*b && first_smallest_last(b) && rrb(b, 1));
		else if (*a && smallest_last_and_second(a) && rra(a, 1) && sa(a, 1));
		else if (*a && !ascending_order(a) && pb(a, b, 1))
		{
			if (*b && (*b)->next && (*b)->n < (*b)->next->n)
				sb(b, 1);
		}
		else if (*b && descending_order(b) && ascending_order(a) && pa(a, b, 1));
		else
			pb(a, b, 1);
		if (print)
			print_stacks(a, b);
	}
}

int	main(int argc, char **argv)
{
	Stack	*a;
	Stack	*b;

	a = NULL;
	b = NULL;
	if (verification_part1(argc, argv) || verification_part2(argv, &a))
		return (!write(1, "Error\n", 6));
	operator_algorithm(&a, &b, 0);
	free_list(&a);
	free_list(&b);
	return (0);
}

//	MAIN WITH VISUAL RESULT AFTER EACH OPERATION
// int	main(int argc, char **argv)
// {
// 	Stack	*a;
// 	Stack	*b;

// 	a = NULL;
// 	b = NULL;
// 	if(verification_part1(argc, argv) || verification_part2(argv, &a))
// 		return (!write(1, "Error\n", 6));
// 	print_stacks(&a, &b);
// 	write(1, "\nExec: \n", 8);
// 	operator_algorithm(&a, &b, 1);
// 	write(1, "\n", 1);
// 	print_stacks(&a, &b);
// 	free_list(&a);
// 	free_list(&b);
// 	return (0);
// }
