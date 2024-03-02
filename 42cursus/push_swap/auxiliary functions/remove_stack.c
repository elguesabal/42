/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:13:29 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/01 18:35:28 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*remove_first(t_stack **no)
{
	t_stack	*remove;

	remove = NULL;
	if (*no)
	{
		remove = *no;
		*no = remove->next;
		if (*no)
			(*no)->previous = NULL;
	}
	return (remove);
}

t_stack	*remove_second(t_stack **no)
{
	t_stack	*remove;

	remove = NULL;
	if (!*no || !(*no)->next)
		return (remove);
	else
	{
		remove = (*no)->next;
		if ((*no)->next->next)
		{
			(*no)->next = (*no)->next->next;
			(*no)->next->previous = *no;
		}
		else
			(*no)->next = NULL;
	}
	return (remove);
}

t_stack	*remove_last(t_stack **no)
{
	t_stack	*remove;
	t_stack	*assist;

	remove = NULL;
	if (*no)
	{
		assist = *no;
		while (assist->next)
			assist = assist->next;
		remove = assist;
		assist->previous->next = NULL;
	}
	return (remove);
}
