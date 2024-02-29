/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_assist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 07:59:58 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/29 19:17:02 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	search_duplicate(Stack **no)
{
	Stack	*assist1;
	Stack	*assist2;
	int		n;
	int		count;

	assist1 = *no;
	while (assist1)
	{
		assist2 = *no;
		n = assist1->n;
		count = 0;
		while (assist2)
		{
			if (n == assist2->n)
				count++;
			if (count > 1)
				return (1);
			assist2 = assist2->next;
		}
		assist1 = assist1->next;
	}
	return (0);
}

int	verification_part1(int argc, char **argv, int i)
{
	int		j;

	if (argc == 1)
		return (1);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] || j == 0)
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] == '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	verification_part2(char **argv, Stack **a, int i)
{
	long	n;

	while (argv[i])
	{
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (free_list(a));
		insert_last(a, n, -1);
		i++;
	}
	if (search_duplicate(a))
		return (free_list(a));
	return (0);
}

int	free_list(Stack **no)
{
	Stack	*assist;

	assist = *no;
	while (assist)
	{
		*no = (*no)->next;
		free(assist);
		assist = *no;
	}
	return (1);
}

int	free_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	return (1);
}

void	print_stacks(Stack **a, Stack **b)
{
	Stack	*assist_a;
	Stack	*assist_b;

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
