/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:49:04 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/01 18:34:33 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				n;
	int				index;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

// insert_stack.c
void	insert_first(t_stack **no, int n, int index);
void	insert_last(t_stack **no, int n, int index);

// remove_stack.c
t_stack	*remove_first(t_stack **no);
t_stack	*remove_second(t_stack **no);
t_stack	*remove_last(t_stack **no);

// operations_part1.c
int		sa(t_stack **a, int print);
int		sb(t_stack **b, int print);
int		ss(t_stack **a, t_stack **b, int print);
int		pa(t_stack **a, t_stack **b, int print);

// operations_part2.c
int		pb(t_stack **a, t_stack **b, int print);
int		ra(t_stack **a, int print);
int		rb(t_stack **b, int print);
int		rr(t_stack **a, t_stack **b, int print);

// operations_part3.c
int		rra(t_stack **a, int print);
int		rrb(t_stack **b, int print);
int		rrr(t_stack **a, t_stack **b, int print);

// algorithm1.c
int		count_max_of_bits(int nb);
int		index_max(t_stack *stake);
void	reposition_small_node(t_stack **stack_a, t_stack *n_small, int count);
t_stack	*small_node(t_stack *stack);
void	index_list(t_stack **stack);

// algorithm2.c
void	sort_tree(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_list(t_stack **stack_a, t_stack **stack_b);

// func_assist1.c
int		search_duplicate(t_stack **no);
int		verification_part1(int argc, char **argv, int i);
int		verification_part2(char **argv, t_stack **a, int i);
int		free_list(t_stack **no);
int		free_split(char **argv);

// func_assist2.c
int		size_stack(t_stack **no);
int		stack_check(t_stack *list);
// void	print_stacks(t_stack **a, t_stack **b);

// utils1.c
size_t	ft_strlen(const char *str);
int		check_char(char c, char const *set);
size_t	len_start(char const *s1, char const *set);
size_t	len_end(size_t e, size_t s, char const *s1, char const *set);
char	*ft_strtrim(char const *s1, char const *set);

// utils2.c
int		amontw(char const *s, char c);
char	**ft_mallsplit(char const *s, char **r, char c);
void	ft_fillsplit(char const *s, char **r, char c);
void	ft_freesplit(char *aux, char c, char **r);
char	**ft_split(char const *s, char c);

// utils3.c
long	ft_atoi(const char *str);
void	ft_putnbr(int n);

#endif