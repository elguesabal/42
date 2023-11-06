/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:14:28 by joseanto          #+#    #+#             */
/*   Updated: 2023/11/05 18:38:07 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	int	len;
	va_list args;
	va_start(args, str);

	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
				len += ft_printc(va_arg(args, int));
			else if (*str == 's')
				len += ft_prints(va_arg(args, char *));
			else if (*str == 'p')
				len += ft_printp(va_arg(args, unsigned long int));
			else if (*str == 'd' || *str == 'i')
				len += ft_printd(va_arg(args, int));
			else if (*str == 'u')
				len += ft_printu(va_arg(args, unsigned int));
			else if (*str == 'x')
				len += ft_printx(va_arg(args, unsigned int), 'a');
			else if (*str == 'X')
				len += ft_printx(va_arg(args, unsigned int), 'A');
			else if (*str == '%')
				len += ft_printc('%');
		}
		else
			len += ft_printc(*str);
		str++;
	}
	va_end(args);
	return (len);
}
