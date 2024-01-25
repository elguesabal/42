/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:49:04 by joseanto          #+#    #+#             */
/*   Updated: 2024/01/23 13:54:27 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct stack
{
	int				n;
	struct stack	*next;
	struct stack	*previous;
} Stack;

int	ft_atoi(const char *str);

void	insert_first(Stack **no, int n);
void	insert_second(Stack **no, int n);
void	insert_penultimate(Stack **no, int n);
void	insert_last(Stack **no, int n);
Stack	*remove_first(Stack **no);
Stack	*remove_second(Stack **no);
Stack	*remove_penultimate(Stack **no);
Stack	*remove_last(Stack **no);


#endif