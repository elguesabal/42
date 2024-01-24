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

void	insert_first(Stack **no, int n)
{
	Stack	*new;

	new = malloc(sizeof(Stack));
	if(!new)
		return ;
	new->n = n;
	new->next = *no;
	new->previous = NULL;
	if(*no)
		(*no)->previous = new;
	*no = new;
}

void	insert_second(Stack **no, int n)
{
	
}

void	insert_penultimate(Stack **no, int n)
{
	
}

void	insert_last(Stack **no, int n)
{
	Stack	*new;
	Stack	*assist;

	new = malloc(sizeof(Stack));
	if(!new)
		return ;
	new->n = n;
	new->next = NULL;
	if(!*no)
	{
		*no = new;
		new->previous = NULL;
	}
	else
	{
		assist = *no;
		while(assist->next)
			assist = assist->next;
		assist->next = new;
		new->previous = assist;
	}
}

Stack	*remove_first(Stack **no)
{
	Stack	*remove;

	if(*no)
	{
		remove = *no;
		*no = remove->next;
		if(*no)
			(*no)->previous = NULL;
	}
	return (remove);
}

void	remove_second(Stack **no, int n)
{

}

void	remove_penultimate(Stack **no, int n)
{
	
}

Stack	*remove_last(Stack **no)
{
	Stack	*remove;
	Stack	*assist;

	if(*no)
	{
		assist = *no;
		while(assist->next)
			assist = assist->next;
		remove = assist;
		assist->previous->next = NULL;
	}
	return (remove);
}

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

void imprimir(Stack *no) {
	printf("Lista: ");
	while(no) {
		printf("%d ", no->n);
		no = no->next;
	}
}

int	main(int argc, char **argv)
{
	Stack	*a, *b;

	a = NULL;
	b = NULL;
	
	insert_first(&a, 10);
	insert_first(&a, 20);
	insert_first(&a, 30);
	imprimir(a);

	// Stack *teste = remove_first(&a);
	// printf("\n\nPrimeiro elemento removido: %d\n\n", teste->n);
	// free(teste);
	// imprimir(a);

	// Stack *teste = remove_last(&a);
	// printf("\n\nUltimo elemento removido: %d\n\n", teste->n);
	// free(teste);
	// imprimir(a);







// printf("%d\n", a->n);
// printf("%d\n", a->next->n);
// printf("%d\n", a->next->next->n);
	return (0);
}
