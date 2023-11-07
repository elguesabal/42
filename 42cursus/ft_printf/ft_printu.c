/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:42:25 by joseanto          #+#    #+#             */
/*   Updated: 2023/11/07 11:45:33 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printu(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_printu(n / 10);
		i += ft_printu(n % 10);
	}
	else
		i += ft_printc(n + 48);
	return (i);
}
