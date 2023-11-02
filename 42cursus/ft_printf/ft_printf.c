/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:14:28 by joseanto          #+#    #+#             */
/*   Updated: 2023/11/02 17:07:07 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c) {
	return (write(1, &c, 1));
}

void	ft_putstr(char *str)	// TEMPORARIAMENTE VOID
{
	while (*str)
	{
		ft_putchar(*str++);
	}
}

void	ft_putnbr(int n)	// TEMPORARIAMENTE VOID
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + 48);
	}
}

int	ft_printf(const char *str, ...)
{
	int i;
	va_list args;
	va_start(args, str);

// printf("%s\n", str);
// printf("%d\n", va_arg(args, int));
// printf("%d\n", va_arg(args, int));
// printf("%d\n", va_arg(args, int));

// ft_putchar(va_arg(args, int));
// ft_putchar(va_arg(args, int));
// ft_putchar(va_arg(args, int));
// ft_putchar(va_arg(args, int));
// ft_putchar(va_arg(args, int));
// ft_putchar(va_arg(args, int));

// for(int i = 0; i < 7; i++) {
// 	printf("va_arg: %c\ti: %d\n", va_arg(args, int), i);
// }
// for(int i = 0; i < 10; i++) {
// 	printf("va_arg: %c\ti: %d\n", va_arg(args, int), i);
// }

	i = 0; // PQ EU CRIEI ESSE i??
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
			{
				ft_putchar(va_arg(args, int));
			}
			else if (*str == 's')
			{
				ft_putstr(va_arg(args, char *));
			}
			else if (*str == 'p')
			{
				
			}
			else if (*str == 'd')
			{
				ft_putnbr(va_arg(args, int));
			}
			else if (*str == 'i')
			{
				
			}
			else if (*str == 'u')
			{

			}
			else if (*str == 'x')
			{
				
			}
			else if (*str == 'X')
			{
				
			}
			else if (*str == '%')
			{
				ft_putchar('%');
			}
		}
		else
		{
			ft_putchar(*str);
		}
		*str++;
	}
	va_end(args);
}

int	main(void)
{
	ft_printf("testando: %d", -10);
// ft_putstr("teste");
// ft_putnbr(-50);
	return (0);
}