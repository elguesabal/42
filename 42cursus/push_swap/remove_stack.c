/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:13:29 by joseanto          #+#    #+#             */
/*   Updated: 2024/01/26 14:13:30 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Stack	*remove_first(Stack **no)
{
	Stack	*remove;

	remove = NULL;
	if(*no)
	{
		remove = *no;
		*no = remove->next;
		if(*no)
			(*no)->previous = NULL;
	}
	return (remove);
}

Stack	*remove_second(Stack **no)
{
	Stack	*remove;

	remove = NULL;
	if(!*no || !(*no)->next)
		return (remove);
	else
	{
		remove = (*no)->next;
		(*no)->next = (*no)->next->next;
		(*no)->next->previous = *no;
	}
	return (remove);
}

Stack	*remove_penultimate(Stack **no)
{
	Stack	*remove;
	Stack	*assist;

	remove = NULL;
	if(!*no || (*no && !(*no)->next->next))
		return (remove);
	else
	{
		assist = *no;
		while(assist->next->next)
			assist = assist->next;
		remove = assist;
		assist->previous->next = assist->next;
		assist->next->previous = assist->previous;
	}
	return (remove);
}

Stack	*remove_last(Stack **no)
{
	Stack	*remove;
	Stack	*assist;

	remove = NULL;
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