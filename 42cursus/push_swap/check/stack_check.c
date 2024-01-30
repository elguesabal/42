/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:25:43 by joseanto          #+#    #+#             */
/*   Updated: 2024/01/30 19:07:16 by joseanto         ###   ########.fr       */
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