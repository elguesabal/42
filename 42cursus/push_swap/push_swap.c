/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:21:35 by joseanto          #+#    #+#             */
/*   Updated: 2024/01/30 18:59:40 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_check(Stack **a, Stack **b)
{
	Stack	*assist_a;

	if(!*a || *b)
		return (1);
	assist_a = (*a)->next;
	while(assist_a)
	{
		if(assist_a->previous->n > assist_a->n)
			return (1);
		assist_a = assist_a->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	Stack	*a;
	Stack	*b;

	a = NULL;
	b = NULL;

	if(verification(argc, argv, &a))
	{
		write(1, "Error\n", 6);
		return (0);
	}


insert_last(&b, 1);
insert_last(&b, 3);
insert_last(&b, 2);
	print_stacks(&a, &b);


	write(1, "\nExec: \n", 8);
	while(stack_check(&a, &b))
	{
		if(a && first_biggest_last(&a) && b && first_smallest_last(&b))
		{
			rr(&a, &b);
			write(1, "rr\n", 3);
		}
		else if(a && first_biggest_last(&a))
		{
			ra(&a);
			write(1, "ra\n", 3);
		}
		else if(b && first_smallest_last(&b))
		{
			rb(&b);
			write(1, "rb\n", 3);
		}
		else if(a && first_biggest_last(&a) && b && first_smallest_last(&b))
		{
			rrr(&a, &b);
			write(1, "rrr\n", 4);
		}
		else if(a && first_biggest_last(&a))
		{
			rra(&a);
			write(1, "rra\n", 4);
		}
		else if(b && first_smallest_last(&b))
		{
			rrb(&b);
			write(1, "rrb\n", 4);
		}
		else if(bigger_than_next(&a) && smaller_than_next(&b))
		{
			ss(&a, &b);
			write(1, "ss\n", 3);
		}
		else if(bigger_than_next(&a))
		{
			sa(&a);
			write(1, "sa\n", 3);
		}
		else if(smaller_than_next(&b))
		{
			sb(&b);
			write(1, "sb\n", 3);
		}
		else if(b && descending_order(&b))
		{
			pa(&a, &b);
			write(1, "pa\n", 3);
		}
// print_stacks(&a, &b);
	}
	write(1, "\n", 1);


	print_stacks(&a, &b);
// write(1, "\nfim\n", 5);

	free_list(&a);
	free_list(&b);
	return (0);
}









			// CODIGO PRA TESTAR FUNCOES PEDIDAS PELO PDF

	// sa(&a);
	// print_stacks(&a, &b);

	// sb(&b);
	// print_stacks(&a, &b);

	// ss(&a, &b);
	// print_stacks(&a, &b);

	// pa(&a, &b);
	// print_stacks(&a, &b);

	// pb(&a, &b);
	// print_stacks(&a, &b);

	// ra(&a);
	// print_stacks(&a, &b);

	// rb(&b);
	// print_stacks(&a, &b);

	// rr(&a, &b);
	// print_stacks(&a, &b);

	// rra(&a);
	// print_stacks(&a, &b);

	// rrb(&b);
	// print_stacks(&a, &b);

	// rrr(&a, &b);
	// print_stacks(&a, &b);

			// CODIGO PRA TESTAR FUNCOES PEDIDAS PELO PDF





			// CODIGO PRA TESTAR FUNCOES DE INSERCAO E REMOCAO DE LISTA

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

			// CODIGO PRA TESTAR FUNCOES DE INSERCAO E REMOCAO DE LISTA





			// CODIGO Q TALVEZ EU POSSA UTILIZAR

// Stack	*search(Stack **no, int n) // PESQUISA UM NUMERO E DEVOLVE O NO DO NUMERO
// {
// 	Stack	*num;
// 	Stack	*assist;

// 	num = NULL;
// 	assist = *no;
// 	while(assist && assist->n != n)
// 		assist = assist->next;
// 	if(assist)
// 		num = assist;
// 	return (num);
// }

// void imprimir(Stack *no) {
// 	printf("Lista: ");
// 	while(no) {
// 		printf("%d ", no->n);
// 		no = no->next;
// 	}
// 	printf("\n");
// }
			// CODIGO Q TALVEZ EU POSSA UTILIZAR
