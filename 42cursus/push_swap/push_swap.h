/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:49:04 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/06 10:40:25 by joseanto         ###   ########.fr       */
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
void	insert_last(Stack **no, int n);
// void	insert_second(Stack **no, int n);
// void	insert_penultimate(Stack **no, int n);

// remove_stack.c
Stack	*remove_first(Stack **no);
Stack	*remove_second(Stack **no);
Stack	*remove_last(Stack **no);
// Stack	*remove_penultimate(Stack **no);

// operations_part1.c
int	sa(Stack **a, int print);
int	sb(Stack **b, int print);
int	ss(Stack **a, Stack **b, int print);
int	pa(Stack **a, Stack **b, int print);

// operations_part2.c
int	pb(Stack **a, Stack **b, int print);
int	ra(Stack **a, int print);
int	rb(Stack **b, int print);
int	rr(Stack **a, Stack **b, int print);

// operations_part3.c
int	rra(Stack **a, int print);
int	rrb(Stack **b, int print);
int	rrr(Stack **a, Stack **b, int print);

// stack_check_part1.c
int bigger_than_next(Stack **no);
int smaller_than_next(Stack **no);
int	ascending_order(Stack **no);
int	descending_order(Stack **no);
int	first_biggest_last(Stack **no);

// stack_check_part2.c
int	first_smallest_last(Stack **no);
int	smallest_last_and_second(Stack **no);
// int	last_smallest_first(Stack **no);
// int	last_greatest_first(Stack **no);
// int	size_stack(Stack **no);		// ESSA FAZ A MESMA COISA Q list_size()
// int	list_size(t_stk *list);		// ESSA FAZ A MESMA COISA Q size_stack()
// Stack *last_element(Stack **no);

// func_assist.c
int		search_duplicate(Stack **no);
int		verification_part1(int argc, char **argv, int i);
int		verification_part2(char **argv, Stack **a, int i);
int		free_list(Stack **no);
int		free_split(char **argv);
void	print_stacks(Stack **a, Stack **b);

// utils1.c
size_t	ft_strlen(const char *str);
int	check_char(char c, char const *set);
size_t	len_start(char const *s1, char const *set);
size_t	len_end(size_t e, size_t s, char const *s1, char const *set);
char	*ft_strtrim(char const *s1, char const *set);

// utils2.c
int	amontw(char const *s, char c);
char	**ft_mallsplit(char const *s, char **r, char c);
void	ft_fillsplit(char const *s, char **r, char c);
void	ft_freesplit(char *aux, char c, char **r);
char	**ft_split(char const *s, char c);

// utils3.c
long	ft_atoi(const char *str);
void	ft_putnbr(int n);


#endif