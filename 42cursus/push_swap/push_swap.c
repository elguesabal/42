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

void	sa(Stack **a)
{
	Stack	*remove;

	if(*a && (*a)->next)
	{
		remove = remove_second(a);
		insert_first(a, remove->n);
		free(remove);
	}
}

void	sb(Stack **b)
{
	Stack	*remove;

	if(*b && (*b)->next)
	{
		remove = remove_second(b);
		insert_first(b, remove->n);
		free(remove);
	}
}

void	ss(Stack **a, Stack **b)
{
	sa(a);
	sb(b);
}

void	pa(Stack **a, Stack **b)
{
	Stack	*remove;

	if(*b)
	{
		remove = remove_first(b);
		insert_first(a, remove->n);
		free(remove);
	}
}

void	pb(Stack **a, Stack **b)
{
	Stack	*remove;

	if(*a)
	{
		remove = remove_first(a);
		insert_first(b, remove->n);
		free(remove);
	}
}

void	ra(Stack **a)
{
	Stack	*remove;

	if(*a && (*a)->next)
	{
		remove = remove_first(a);
		insert_last(a, remove->n);
		free(remove);
	}
}

void	rb(Stack **b)
{
	Stack	*remove;

	if(*b && (*b)->next)
	{
		remove = remove_first(b);
		insert_last(b, remove->n);
		free(remove);
	}
}

void	rr(Stack **a, Stack **b)
{	// TA ERRADO
	ra(a);
	rb(b);
}

// void	rra()
// {
	
// }

// void	rrb()
// {
	
// }

// void	rrr()
// {
	
// }

int	main(int argc, char **argv)
{
	Stack	*a;
	Stack	*b;

	a = NULL;
	b = NULL;

	if(verification(argc, argv, &a))
		return (0);

insert_last(&b, 3);
insert_last(&b, 2);
insert_last(&b, 1);

	print_stacks(&a, &b);


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

	rr(&a, &b);	// TA ERRADO
	print_stacks(&a, &b);


	free_list(&a);
	free_list(&b);
	return (0);
}










			// CODIGO PRA TESTAR ALGUMAS FUNCOES

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

			// CODIGO PRA TESTAR ALGUMAS FUNCOES





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
