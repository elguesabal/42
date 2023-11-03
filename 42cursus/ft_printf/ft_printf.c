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
static size_t	ft_countpercent(const char *str) 	// NAO USADO AINDA
{
	size_t	i;
	const char	*ptr;

	ptr = str;
	i = 0;
	while (ptr = strchr(ptr, '%'))
	{
		ptr++;
		i++;
		if (*ptr == '%')
		{
			i--;
		}
	}
printf("return: %d", i);
	return (i);
}

static int	ft_printc(const char c) {
	return (write(1, &c, 1));
}

static void	ft_prints(char *str)	// TEMPORARIAMENTE VOID
{
	while (*str)
	{
		ft_printc(*str++);
	}
}

static void	ft_printd(int n)
{
	if (n == -2147483648)
	{
		ft_printc('-');
		ft_printc('2');
		ft_printd(147483648);
		return ;
	}
	if (n < 0)
	{
		ft_printc('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_printd(n / 10);
		ft_printd(n % 10);
	}
	else
	{
		ft_printc(n + 48);
	}
}

static void	ft_printu(unsigned int n)	// TEMPORARIAMENTE VOID
{
	if (n >= 10)
	{
		ft_printu(n / 10);
		ft_printu(n % 10);
	}
	else
	{
		ft_printc(n + 48);
	}
}

static int ft_printx(unsigned int n, const char c)	// TEMPORARIAMENTE NAO RETORNANDO O LEN IMPRESSA
{
    if (n == 0)
	{
        write(1, "0", 1);
        return (1);
    }

    int copy = n;
    char hexaDecimal[100]; // Um array para armazenar os dígitos hexadecimais
    int i = 0;

    while (n > 0)
	{
        int resto = n % 16;

        // Converte números de 10 a 15 para letras A-F
        if (resto < 10) {
            hexaDecimal[i] = resto + '0';
        } else {
            hexaDecimal[i] = resto - 10 + c;
        }
        i++;
        n = n / 16;
    }

    printf("Número decimal %d em hexadecimal: ", copy);

    // Imprime os dígitos hexadecimais em ordem reversa
    for (int j = i - 1; j >= 0; j--)
	{
        write(1, &hexaDecimal[j], 1);
    }
    // printf("\n");
}

int	ft_printf(const char *str, ...)
{
	int	i;
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

	i = 0; // PQ EU CRIEI ESSE i?? TALVEZ EU USE ESSE i PRA CONTAR O TAMANHO DA NOVA STRING
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
			{
				ft_printc(va_arg(args, int));
			}
			else if (*str == 's')
			{
				ft_prints(va_arg(args, char *));
			}
			else if (*str == 'p')
			{
				
			}
			else if (*str == 'd')
			{
				ft_printd(va_arg(args, int));
			}
			else if (*str == 'i')
			{
				ft_printd(va_arg(args, int));	// TEMPORARIAMENTE USANDO ft_printd PQ AINDA NAO IDENTIFIQUEI NENHUMA DIFERENCA Q SEJA PEGA PELA MOULINETTE
			}
			else if (*str == 'u')
			{
				ft_printu(va_arg(args, unsigned int));
			}
			else if (*str == 'x')
			{
				ft_printx(va_arg(args, unsigned int), 'a');
			}
			else if (*str == 'X')
			{
				ft_printx(va_arg(args, unsigned int), 'A');
			}
			else if (*str == '%')
			{
				ft_printc('%');
			}
		}
		else
		{
			ft_printc(*str);
		}
		*str++;
	}
	va_end(args);
	return (1);	// RETORNAR O TAMANHO DA STRING FINAL
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

printf("%X", 255453);
	return (0);
}