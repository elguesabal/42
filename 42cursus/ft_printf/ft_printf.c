/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:14:28 by joseanto          #+#    #+#             */
/*   Updated: 2023/11/07 15:48:25 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conditional(va_list args, const char *str)
{
	if (*str == 'c')
		return (ft_printc(va_arg(args, int)));
	else if (*str == 's')
		return (ft_prints(va_arg(args, char *)));
	else if (*str == 'p')
		return (ft_printp(va_arg(args, unsigned long long)));
	else if (*str == 'd' || *str == 'i')
		return (ft_printd(va_arg(args, int)));
	else if (*str == 'u')
		return (ft_printu(va_arg(args, unsigned int)));
	else if (*str == 'x')
		return (ft_printx(va_arg(args, unsigned int), 'a'));
	else if (*str == 'X')
		return (ft_printx(va_arg(args, unsigned int), 'A'));
	else if (*str == '%')
		return (ft_printc('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	va_start(args, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += conditional(args, str);
		}
		else
			len += ft_printc(*str);
		str++;
	}
	va_end(args);
	return (len);
}
