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

// CONTA QUANTOS % TEM NA STRING
// static size_t	ft_countpercent(const char *str) 	// NAO USADO AINDA
// {
// 	size_t	i;
// 	const char	*ptr;

// 	ptr = str;
// 	i = 0;
// 	while (ptr = strchr(ptr, '%'))
// 	{
// 		ptr++;
// 		i++;
// 		if (*ptr == '%')
// 		{
// 			i--;
// 		}
// 	}
// printf("return: %d", i);
// 	return (i);
// }

static int	ft_printc(const char c) {
	return (write(1, &c, 1));
}

static int	ft_prints(char *str)	// TEMPORARIAMENTE VOID
{
	int	i;

	i = 0;
	while (str[i])
	{
		i += ft_printc(str[i]);
		// i++;
	}
//printf("\nreturn: %d\n", i);
	return (i);
}

static int	ft_printd(int n)	// TEMPORARIAMENTE VOID
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += ft_printc('-');
		i += ft_printc('2');
		i += ft_printd(147483648);
		return (i);
	}
	if (n < 0)
	{
		i += ft_printc('-');
		n = -n;
	}
	if (n >= 10)
	{
		i += ft_printd(n / 10);
		i += ft_printd(n % 10);
	}
	else
	{
		i += ft_printc(n + 48);
	}
	return (i);
}

static unsigned int	ft_printu(unsigned int n)	// TEMPORARIAMENTE VOID
{
	unsigned int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_printu(n / 10);
		i += ft_printu(n % 10);
	}
	else
	{
		i += ft_printc(n + 48);
	}
	return (i);
}

static unsigned int	ft_printx(unsigned int n, const char c)	// TEMPORARIAMENTE NAO RETORNANDO O LEN IMPRESSA
{
	// // int copy = n;
	// char hexadecimal[100]; // Um array para armazenar os digitos hexadecimais
	// unsigned int i;
	// unsigned int len;
	// int rest;

	// if (n == 0)
	// {
	// 	// write(1, "0", 1);
	// 	return (write(1, "0", 1));
	// }
	// i = 0;
	// while (n > 0)
	// {
	// 	// rest = n % 16;

	// 	// Converte numeros de 10 a 15 para letras A-F
	// 	if (n % 16 < 10)
	// 	{
	// 		hexadecimal[i] = n % 16 + '0';
	// 	}
	// 	else
	// 	{
	// 		hexadecimal[i] = n % 16 - 10 + c;
	// 	}
	// 	i++;
	// 	n = n / 16;
	// }

	// // printf("Numero decimal %d em hexadecimal: ", copy);

	// // Imprime os digitos hexadecimais em ordem reversa
	// //len = i;
	// i--;
	// while (i >= 0)
	// {
	// 	write(1, &hexadecimal[i], 1);
	// 	i--;
	// }
	// // printf("\n");
	// //return (len);




	// int numeroOriginal = n;
	char hexadecimal[100]; // Um array para armazenar os digitos hexadecimais
	int rest;
	int i;
	int j;

	if (n == 0) {
		return (write(1, "0", 1));
	}
	i = 0;
	while (n > 0)
	{
		rest = n % 16;

		// Converte numeros de 10 a 15 para letras A-F
		if (rest < 10)
		{
			hexadecimal[i] = rest + '0';
		}
		else
		{
			hexadecimal[i] = rest - 10 + c;
		}
		i++;
		n = n / 16;
	}

	// printf("Número decimal %d em hexadecimal: ", numeroOriginal);

	// Imprime os digitos hexadecimais em ordem reversa
	// for (int j = i - 1; j >= 0; j--)
	// {
	// 	write(1, &hexadecimal[j], 1);
	// }
	j = i - 1;
	while (j >= 0)
	{
		write(1, &hexadecimal[j], 1);
		j--;
	}
	// printf("\n");
	return (i);
}

int	ft_printf(const char *str, ...)
{
	unsigned int	len;
	va_list args;
	va_start(args, str);

// printf("%s\n", str);
// printf("%d\n", va_arg(args, int));
// printf("%d\n", va_arg(args, int));
// printf("%d\n", va_arg(args, int));

// ft_printc(va_arg(args, int));
// ft_printc(va_arg(args, int));
// ft_printc(va_arg(args, int));
// ft_printc(va_arg(args, int));
// ft_printc(va_arg(args, int));
// ft_printc(va_arg(args, int));

// for(int i = 0; i < 7; i++) {
// 	printf("va_arg: %c\ti: %d\n", va_arg(args, int), i);
// }
// for(int i = 0; i < 10; i++) {
// 	printf("va_arg: %c\ti: %d\n", va_arg(args, int), i);
// }

	// i = 0; // PQ EU CRIEI ESSE i?? TALVEZ EU USE ESSE i PRA CONTAR O TAMANHO DA NOVA STRING
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
	return (len);	// RETORNAR O TAMANHO DA STRING FINAL
}

int	main(void)
{
	// ft_printf("testando: %u", 10000);
// ft_prints("teste");
// ft_printd(-50);
// ft_countpercent("teste % codig%%o");

// int decimal = 42;
// int octal = 052; // O prefixo 0 indica um número octal (base 8)
// int hexadecimal = 0x2A; // O prefixo 0x ou 0X indica um número hexadecimal (base 16)
// ft_printf("Decimal: %d\n", decimal); // Imprime 42 em decimal
// ft_printf("Octal: %d\n", octal); // Imprime 42 (052 é interpretado como decimal)
// ft_printf("Hexadecimal: %d\n", hexadecimal); // Imprime 42 (0x2A é interpretado como decimal)

// printf("%X\n", 2554531241414142);
// ft_printf("%X", 2554531241414142);

	int len;

	len = ft_printf("teste%%", 15);
	printf("\n%d\n", len);
	return (0);
}