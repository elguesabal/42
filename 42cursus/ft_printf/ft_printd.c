/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:39:00 by joseanto          #+#    #+#             */
/*   Updated: 2023/11/05 16:49:44 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printd(int n)
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
		i += ft_printc(n + 48);
	return (i);
}
