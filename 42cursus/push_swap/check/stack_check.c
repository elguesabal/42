/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:25:43 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/02 16:06:06 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int bigger_than_next(Stack **no)
{
	if(!*no || !(*no)->next)
		return (0);
	return ((*no)->n > (*no)->next->n);
}

int smaller_than_next(Stack **no)
{
	if(!*no || !(*no)->next)
		return (0);
	return ((*no)->n < (*no)->next->n);
}

int	ascending_order(Stack **no)
{
// write(1, "aki\n", 4);
	Stack	*assist;

	if(!*no)
		return (1);
	assist = (*no)->next;
	while(assist)
	{
		if(assist->previous->n > assist->n)
			return (0);
		assist = assist->next;
	}
	return (1);
}

int	descending_order(Stack **no)
{
// write(1, "aki\n", 4);
	Stack	*assist;

	if(!*no)
		return (1);
	assist = (*no)->next;
	while(assist)
	{
		if(assist->previous->n < assist->n)
			return (0);
		assist = assist->next;
	}
	return (1);
}

int	first_biggest_last(Stack **no)
{
// write(1, "aki\n", 4);
	Stack	*assist;

	if(!*no && !(*no)->next)
		return (0);
	assist = *no;
	while(assist->next)
		assist = assist->next;
	return ((*no)->n > assist->n);
}

int	first_smallest_last(Stack **no)
{
// write(1, "aki\n", 4);
	Stack	*assist;

	if(!*no && !(*no)->next)
		return (0);
	assist = *no;
	while(assist->next)
		assist = assist->next;
	return ((*no)->n < assist->n);
}

int	smallest_last_and_second(Stack **no)
{
// write(1, "aki\n", 4);
	Stack	*assist;

	if(!*no && !(*no)->next && !(*no)->next->next)
		return (0);
	assist = *no;
	while(assist->next)
		assist = assist->next;
int teste = ((*no)->n < (*no)->next->n && (*no)->n < assist->n && assist->n < (*no)->next->n); // NAO ENTENDI AINDA MDS
// write(1, "terminou\n", 9);
	return (teste);
}

// int	last_smallest_first(Stack **no)
// {
// 	Stack	*assist;

// 	if(!*no && !(*no)->next)
// 		return (0);
// 	assist = *no;
// 	while(assist->next)
// 		assist = assist->next;
// 	return (assist->n < (*no)->n);
// }

// int	last_greatest_first(Stack **no)
// {
// 	Stack	*assist;

// 	if(!*no && !(*no)->next)
// 		return (0);
// 	assist = *no;
// 	while(assist->next)
// 		assist = assist->next;
// 	return (assist->n > (*no)->n);
// }






// int	size_stack(Stack **no)
// {
// 	Stack	*assist;
// 	int		size;

// 	assist = *no;
// 	size = 0;
// 	while(assist)
// 	{
// 		assist = assist->next;
// 		size++;
// 	}
// 	return (size);
// }

// Stack *last_element(Stack **no) // AF FIZ ATOA E AGR TA AI CASO PRECISE PEGAR O ULTIMO ELEMENTO DA LISTA
// {
//     Stack   *last;

//     if(!*no)
//         return (NULL);
//     last = *no;
//     while(last->next)
//         last = last->next;
//     return (last);
// }