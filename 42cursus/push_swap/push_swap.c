/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:21:35 by joseanto          #+#    #+#             */
/*   Updated: 2024/01/26 15:42:35 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

// void	sa()
// {
	
// }

// void	sb()
// {
	
// }

// void	ss()
// {
	
// }

// void	pa()
// {
	
// }

// void	pb()
// {
	
// }

// void	ra()
// {
	
// }

// void	rb()
// {
	
// }

// void	rr()
// {
	
// }

// void	rra()
// {
	
// }

// void	rrb()
// {
	
// }

// void	rrr()
// {
	
// }

Stack	*search(Stack **no, int n) // PESQUISA UM NUMERO E DEVOLVE O NO DO NUMERO
{
	Stack	*num;
	Stack	*assist;

	num = NULL;
	assist = *no;
	while(assist && assist->n != n)
		assist = assist->next;
	if(assist)
		num = assist;
	return (num);
}

void	print_stacks(Stack **a, Stack **b)
{
	Stack	*assist_a;
	Stack	*assist_b;

	assist_a = *a;
	assist_b = *b;
	printf("--------------------------------------------\n");
	while(assist_a || assist_b)
	{
		if(assist_a)
			printf("%d ", assist_a->n);
		else
			printf("  ");
		if(assist_a)
			assist_a = assist_a->next;

		if(assist_b)
			printf("%d\n", assist_b->n);
		else
			printf("\n");
		if(assist_b)
			assist_b = assist_b->next;
	}
	printf("\n- -\na b\n");
}

// void imprimir(Stack *no) {
// 	printf("Lista: ");
// 	while(no) {
// 		printf("%d ", no->n);
// 		no = no->next;
// 	}
// 	printf("\n");
// }

int	main(int argc, char **argv)
{
	Stack	*a;
	Stack	*b;
	int		i;
	int		j;
	long	n;

	a = NULL;
	b = NULL;
	if(argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);


	i = 1;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-' && argv[i][j] != '+')
				return (0);
			j++;
		}
		i++;
	}


	i = 1;
	while(argv[i])
	{
		n = ft_atoi(argv[i]);
		if(n > INT_MAX || n < INT_MIN)
			return (0);
		insert_last(&a, n);
		i++;
	}


	// FALTA VERIFICA SE EXISTE DUPLICATAS NO ARGUMENTO

	
	print_stacks(&a, &b);
	// imprimir(a);










	// insert_first(&a, 10);
	// insert_first(&a, 20);
	// insert_first(&a, 30);
	// imprimir(a);

	// insert_first(&a, 35);
	// imprimir(a);

	// insert_second(&a, 25);
	// imprimir(a);

	// insert_penultimate(&a, 15);
	// imprimir(a);

	// insert_last(&a, 5);
	// imprimir(a);

	// Stack *teste = remove_first(&a);
	// printf("\n\nPrimeiro elemento removido: %d\n\n", teste->n);
	// free(teste);
	// imprimir(a);

	// Stack *teste = remove_second(&a);
	// printf("\n\nSegundo elemento removido: %d\n\n", teste->n);
	// free(teste);
	// imprimir(a);

	// Stack *teste = remove_penultimate(&a);
	// printf("\n\nPenultimo elemento removido: %d\n\n", teste->n);
	// free(teste);
	// imprimir(a);

	// Stack *teste = remove_last(&a);
	// printf("\n\nUltimo elemento removido: %d\n\n", teste->n);
	// free(teste);
	// imprimir(a);

	return (0);
}
