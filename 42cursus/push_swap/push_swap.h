/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:49:04 by joseanto          #+#    #+#             */
/*   Updated: 2024/01/26 15:40:43 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct stack
{
	int				n;
	struct stack	*next;
	struct stack	*previous;
} Stack;


// insert_stack.c
void	insert_first(Stack **no, int n);
void	insert_second(Stack **no, int n);
void	insert_penultimate(Stack **no, int n);
void	insert_last(Stack **no, int n);

// remove_stack.c
Stack	*remove_first(Stack **no);
Stack	*remove_second(Stack **no);
Stack	*remove_penultimate(Stack **no);
Stack	*remove_last(Stack **no);

// operations_part1.c
void	sa(Stack **a);
void	sb(Stack **b);
void	ss(Stack **a, Stack **b);
void	pa(Stack **a, Stack **b);

// operations_part2.c
void	pb(Stack **a, Stack **b);
void	ra(Stack **a);
void	rb(Stack **b);
void	rr(Stack **a, Stack **b);

// operations_part3.c
void	rra(Stack **a);
void	rrb(Stack **b);
void	rrr(Stack **a, Stack **b);

// func_assist.c
int		search_duplicate(Stack **no);
int		verification(int argc, char **argv, Stack **a);
void	print_stacks(Stack **a, Stack **b);
void	free_list(Stack **no);

// utils.c
long	ft_atoi(const char *str);
int		ft_putnbr(int n);


#endif