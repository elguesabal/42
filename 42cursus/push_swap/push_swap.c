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

	if(!new)
		return ;
	new->n = n;
	if(!*no)
	{
		new->next = NULL;
		new->previous = NULL;
		*no = new;
	}
	else
	{
		// SL OQ FZ AKI
	}
}

void	remove_first(Stack **no, int n)
{

}

void	remove_second(Stack **no, int n)
{

}

void	remove_penultimate(Stack **no, int n)
{
	
}

void	remove_last(Stack **no, int n)
{

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

int	main(int argc, char **argv)
{
	Stack	*a, *b;

	a = NULL;
	b = NULL;
	
	first(&a, 10);
printf("%d", a->n);
	return (0);
}
