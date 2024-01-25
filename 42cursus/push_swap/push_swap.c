/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:21:35 by joseanto          #+#    #+#             */
/*   Updated: 2024/01/23 18:27:17 by joseanto         ###   ########.fr       */
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

void imprimir(Stack *no) {
	printf("Lista: ");
	while(no) {
		printf("%d ", no->n);
		no = no->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	Stack	*a, *b;
	int		i;
	int		n;

	a = NULL;
	b = NULL;
	i = 1;
	while(argv[i])
	{
		insert_last(&a, ft_atoi(argv[i])); // printf("%d", ft_atoi("1a0")); ?????
		i++;
	}
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
