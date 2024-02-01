/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_assist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 07:59:58 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/01 09:28:24 by joseanto         ###   ########.fr       */
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
	while(assist1)
	{
		assist2 = *no;
		n = assist1->n;
		count = 0;
		while(assist2)
		{
			if(n == assist2->n)
				count++;
			if(count > 1)
				return (1);
			assist2 = assist2->next;
		}
		assist1 = assist1->next;
	}
	return (0);
}

int	verification(int argc, char **argv, Stack **a)
{
	int		i;
	int		j;
	long	n;

	// VERIFICA A QUANTIDADE DE ARGUMENTOS
	if(argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);

	// VERIFICA SE SO TEM NUMERO COMO ARGUMENTO
	i = 1;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-' && argv[i][j] != '+')
				return (1);
			j++;
		}
		i++;
	}

	// VERIFICA SE O NUMERO PASSADO RESPEITA OS LIMITES DE UM INTEIRO E ADICIONA NA LISTA
	i = 1;
	while(argv[i])
	{
		n = ft_atoi(argv[i]);
		if(n > INT_MAX || n < INT_MIN)
		{
			free_list(a);
			return (1);
		}
		insert_last(a, n);
		i++;
	}

	// VERIFICA SE EXISTE DUPLICATAS NO ARGUMENTO
	if(search_duplicate(a))
	{
		free_list(a);
		return (1);
	}

	return (0);
}

void	print_stacks(Stack **a, Stack **b)
{
	Stack	*assist_a;
	Stack	*assist_b;

	assist_a = *a;
	assist_b = *b;
	write(1, "--------------------------------------------\n", 45);
	while(assist_a || assist_b)
	{
		if(assist_a)
		{
			ft_putnbr(assist_a->n);
			write(1, " ", 1);
		}
		else
			write(1, "  ", 2);
		if(assist_a)
			assist_a = assist_a->next;

		if(assist_b)
		{
			ft_putnbr(assist_b->n);
			write(1, "\n", 1);
		}
		else
			write(1, "\n", 1);
		if(assist_b)
			assist_b = assist_b->next;
	}
	write(1, "\n- -\na b\n\n", 10);
}

void	free_list(Stack **no)
{
	while(*no)
	{
		free((*no)->previous);
		*no = (*no)->next;
	}
}
