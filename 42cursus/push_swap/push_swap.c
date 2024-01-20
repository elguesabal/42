/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:21:35 by joseanto          #+#    #+#             */
/*   Updated: 2024/01/12 10:46:38 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	putnbr(int n)
{
	int		i;
	char	c;

	i = 0;
	if (n == -2147483648)
	{
		i += write(1, "-", 1);
		i += write(1, "2", 1);
		i += putnbr(147483648);
		return (i);
	}
	if (n < 0)
	{
		i += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		i += putnbr(n / 10);
		i += putnbr(n % 10);
	}
	else
	{
		c = n + 48;
		i += write(1, &c, 1);
	}
	return (i);
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

void	boot(int argc, char **argv)
{
	printf("%d\n%s\n%s\n%s", argc, argv[0], argv[1], argv[2]);
}

// void	print_result(int size)
// {
// 	// int	mat1[5] = {1, 2, 3, 4, 5};
// 	// int	mat2[5] = {'\0', '\0', '\0', '\0', '\0'};
// 	Stack	a;
// 	Stack	b;
// 	int	i;

// 	a.n = 10;
// 	b.n = 20;
// 	write(1, "---------------------------------------------------------", 58);
// 	i = 0;
// 	while (i < size)
// 	{
// 		putnbr(a.n);
// 		write(1, " ", 1),
// 		putnbr(b.n);
// 		write(1, "\n", 1);
// 		i++;
// 	}
// 	write(1, "- -\na b\n", 9);
// }

int	main(int argc, char **argv)
{
	// boot(argc, argv);
	// print_result(argc - 1);

	return (0);
}
