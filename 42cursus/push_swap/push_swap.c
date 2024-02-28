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

// static int	stack_check(Stack **a, Stack **b) // MODIFIQUEI ESSA FUNCAO PARA SUBISTITUIR check_list_sorted()
// {
// 	Stack	*assist_a;

// 	if (!*a || *b)
// 		return (0);
// 	assist_a = (*a)->next;
// 	while (assist_a)
// 	{
// 		if (assist_a->previous->n > assist_a->n)
// 			return (0);
// 		assist_a = assist_a->next;
// 	}
// 	return (1);
// }

int	check_list_sorted(Stack *list)
{
	Stack	*temp;

	temp = list;
	while (temp->next != NULL)
	{
		if (temp->n > temp->next->n)
			return (0);
		temp = temp->next;
	}
	return (1);
}

// static void	operator_algorithm(Stack **a, Stack **b, int print) // VAI MUDAR O NOME
// {
// 	while (stack_check(a, b))
// 	{
// 		if (bigger_than_next(a) && smaller_than_next(b) && ss(a, b, 1));
// 		else if (bigger_than_next(a) && sa(a, 1));
// 		else if (smaller_than_next(b) && sb(b, 1));
// 		else if (*a && first_biggest_last(a) && *b && first_smallest_last(b) && rr(a, b, 1));
// 		else if (*a && first_biggest_last(a) && ra(a, 1));
// 		else if (*b && first_smallest_last(b) && rb(b, 1));
// 		else if (*a && first_biggest_last(a) && *b && first_smallest_last(b) && rrr(a, b, 1));
// 		else if (*a && first_biggest_last(a) && rra(a, 1));
// 		else if (*b && first_smallest_last(b) && rrb(b, 1));
// 		else if (*a && smallest_last_and_second(a) && rra(a, 1) && sa(a, 1));
// 		else if (*a && !ascending_order(a) && pb(a, b, 1))
// 		{
// 			if (*b && (*b)->next && (*b)->n < (*b)->next->n)
// 				sb(b, 1);
// 		}
// 		else if (*b && descending_order(b) && ascending_order(a) && pa(a, b, 1));
// 		else
// 			pb(a, b, 1);
// 		if (print)
// 			print_stacks(a, b);
// 	}
// }











// ??
int	count_max_of_bits(int nb)
{
	int	count;

	count = 0;
	while (nb > 0)
	{
		count++;
		nb = nb >> 1;
	}
	return (count);
}

// ??
int	index_max(Stack *stake)
{
	Stack	*temp;
	int		max;

	max = -1;
	temp = stake;
	while (temp)
	{
		if (max < temp->index)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}

// ??
void	reposition_small_node(Stack **stack_a, Stack *n_small, int count)
{
	int		param;
	int		size_list;
	Stack	*temp;

	size_list = size_stack(stack_a);
	param = size_list / 2;
	temp = *stack_a;
	while (temp != n_small)
	{
		count++;
		temp = temp->next;
	}
	if (count < param)
	{
		while (*stack_a != n_small)
			ra(stack_a, 1);
	}
	else
	{
		while (*stack_a != n_small)
			rra(stack_a, 1);
	}
}

// ??
Stack	*small_node(Stack *stack)
{
	Stack	*temp;
	Stack	*n_small;
	int		small;

	temp = stack;
	small = size_stack(&stack);
	while (temp)
	{
		if (small > temp->index)
		{
			n_small = temp;
			small = temp->index;
		}
		temp = temp->next;
	}
	return (n_small);
}

// FUNCAO Q GRAVA NA VARIAVEL index DE CADA NO A POSICAO Q CADA NO DEVERIA ESTAR
static void	index_list(Stack **stack)
{
	Stack	*temp;
	Stack	*small;
	int		i;
	int		size_list;
	int		nb;

	i = 0;
	size_list = size_stack(stack);
	while (i < size_list)
	{
		nb = 2147483647;
		temp = *stack;
		while (temp)
		{
			if (nb >= temp->n && temp->index == -1)
			{
				small = temp;
				nb = temp->n;
			}
			temp = temp->next;
		}
		small->index = i;
		i++;
	}
}

// FUNCAO Q ORGANIZA CASO TENHA 3 NUMEROS
void	sort_tree(Stack **stack_a)
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

// FUNCAO Q ORGANIZA CASO TENHA 4 NUMEROS
void	sort_four(Stack **stack_a, Stack **stack_b)
{
	int		count;
	Stack	*n_small;

	count = 0;
	n_small = small_node(*stack_a);
	reposition_small_node(stack_a, n_small, count);
	pb(stack_a, stack_b, 1);
	sort_tree(stack_a);
	pa(stack_b, stack_a, 1);
}

// FUNCAO Q ORGANIZA CASO TENHA 5 NUMEROS
void	sort_five(Stack **stack_a, Stack **stack_b)
{
	int		count;
	Stack	*n_small;

	count = 0;
	n_small = small_node(*stack_a);
	reposition_small_node(stack_a, n_small, count);
	pb(stack_a, stack_b, 1);
	sort_four(stack_a, stack_b);
	pa(stack_b, stack_a, 1);
}

// FUNCAO Q ORGANIZA CASO TENHA MAIS DE 6 NUMEROS
void	radix_sort(Stack **stack_a, Stack **stack_b)
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
			pa(stack_b, stack_a, 1);
		i++;
	}
}

// ALGORITIMO FINAL QUE ORGANIZA OS NUMEROS
static void	sort_list(Stack **stack_a, Stack **stack_b)
{
	if (check_list_sorted(*stack_a))
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











int	main(int argc, char **argv)
{
	Stack	*a;
	Stack	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i--;
	}
	if (verification_part1(argc, argv, i) || verification_part2(argv, &a, i))
	{
		if (argc == 2)
			free_split(argv);
		return (!write(1, "Error\n", 6));
	}
	if (argc == 2)
		free_split(argv);
index_list(&a);
sort_list(&a, &b);
	// operator_algorithm(&a, &b, 0);
	free_list(&a);
	free_list(&b);
	return (0);
}

//	MAIN WITH VISUAL RESULT AFTER EACH OPERATION
// int	main(int argc, char **argv)
// {
// 	Stack	*a;
// 	Stack	*b;
// 	int		i;

// 	a = NULL;
// 	b = NULL;
// 	i = 1;
// 	if (argc == 2)
// 	{
// 		argv = ft_split(argv[1], ' ');
// 		i--;
// 	}
// 	if (verification_part1(argc, argv, i) || verification_part2(argv, &a, i))
// 	{
// 		if (argc == 2)
// 			free_split(argv);
// 		return (!write(1, "Error\n", 6));
// 	}
// 	if (argc == 2)
// 		free_split(argv);
// 	print_stacks(&a, &b);
// 	write(1, "\nExec: \n", 8);
// 	operator_algorithm(&a, &b, 1);
// 	write(1, "\n", 1);
// 	print_stacks(&a, &b);
// 	free_list(&a);
// 	free_list(&b);
// 	return (0);
// }
