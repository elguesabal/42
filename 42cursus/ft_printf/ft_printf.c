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

#include "libftprintf.h"
// #include <stdio.h>

int	ft_printf(const char *str, ...)
{
	unsigned int	len;
	va_list args;
	va_start(args, str);

	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
			{
				len += ft_printc(va_arg(args, int));
			}
			else if (*str == 's')
			{
				len += ft_prints(va_arg(args, char *));
			}
			else if (*str == 'p')
			{
				// COMO VOU FZ ESSA BAGACA???
			}
			else if (*str == 'd')
			{
				len += ft_printd(va_arg(args, int));
			}
			else if (*str == 'i')
			{
				len += ft_printd(va_arg(args, int));	// TEMPORARIAMENTE USANDO ft_printd PQ AINDA NAO IDENTIFIQUEI NENHUMA DIFERENCA Q SEJA PEGA PELA MOULINETTE
			}
			else if (*str == 'u')
			{
				len += ft_printu(va_arg(args, unsigned int));
			}
			else if (*str == 'x')
			{
				len += ft_printx(va_arg(args, unsigned int), 'a');
			}
			else if (*str == 'X')
			{
				len += ft_printx(va_arg(args, unsigned int), 'A');
			}
			else if (*str == '%')
			{
				len += ft_printc('%');
			}
		}
		else
		{
			len += ft_printc(*str);
		}
		*str++;
	}
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	// ft_printf("testando: %u", 10000);
// // ft_prints("teste");
// // ft_printd(-50);
// // ft_countpercent("teste % codig%%o");

// // int decimal = 42;
// // int octal = 052; // O prefixo 0 indica um número octal (base 8)
// // int hexadecimal = 0x2A; // O prefixo 0x ou 0X indica um número hexadecimal (base 16)
// // ft_printf("Decimal: %d\n", decimal); // Imprime 42 em decimal
// // ft_printf("Octal: %d\n", octal); // Imprime 42 (052 é interpretado como decimal)
// // ft_printf("Hexadecimal: %d\n", hexadecimal); // Imprime 42 (0x2A é interpretado como decimal)

// // printf("%%\n", "qwe");
// // ft_printf("%%", "qwe");

// 	// int len;

// 	// len = ft_printf("teste%%", 15);
// 	// printf("\n%d\n", len);
// 	return (0);
// }