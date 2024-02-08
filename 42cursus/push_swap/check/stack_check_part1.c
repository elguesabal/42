/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:25:43 by joseanto          #+#    #+#             */
/*   Updated: 2024/02/06 09:42:43 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	bigger_than_next(Stack **no)
{
	if (!*no || !(*no)->next)
		return (0);
	return ((*no)->n > (*no)->next->n);
}

int	smaller_than_next(Stack **no)
{
	if (!*no || !(*no)->next)
		return (0);
	return ((*no)->n < (*no)->next->n);
}

int	ascending_order(Stack **no)
{
	Stack	*assist;

	if (!*no)
		return (1);
	assist = (*no)->next;
	while (assist)
	{
		if (assist->previous->n > assist->n)
			return (0);
		assist = assist->next;
	}
	return (1);
}

int	descending_order(Stack **no)
{
	Stack	*assist;

	if (!*no)
		return (1);
	assist = (*no)->next;
	while (assist)
	{
		if (assist->previous->n < assist->n)
			return (0);
		assist = assist->next;
	}
	return (1);
}

int	first_biggest_last(Stack **no)
{
	Stack	*assist;

	if (!*no || !(*no)->next)
		return (0);
	assist = *no;
	while (assist->next)
		assist = assist->next;
	return ((*no)->n > assist->n);
}
