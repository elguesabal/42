/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check_part2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:43:19 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/06 09:48:48 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	first_smallest_last(Stack **no)
{
	Stack	*assist;

	if (!*no || !(*no)->next)
		return (0);
	assist = *no;
	while (assist->next)
		assist = assist->next;
	return ((*no)->n < assist->n);
}

int	smallest_last_and_second(Stack **no)
{
	Stack	*assist;

	if (!*no || !(*no)->next || !(*no)->next->next)
		return (0);
	assist = *no;
	while (assist->next)
		assist = assist->next;
	return ((*no)->n < (*no)->next->n && (*no)->n < assist->n
		&& assist->n < (*no)->next->n);
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

// Stack *last_element(Stack **no)
// {
//     Stack   *last;

//     if(!*no)
//         return (NULL);
//     last = *no;
//     while(last->next)
//         last = last->next;
//     return (last);
// }