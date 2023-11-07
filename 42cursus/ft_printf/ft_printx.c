/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:42:50 by joseanto          #+#    #+#             */
/*   Updated: 2023/11/07 11:45:39 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printx(unsigned long long n, const char c)
{
	char	hexadecimal[100];
	int		rest;
	int		i;
	int		j;

	if (n == 0)
		return (write(1, "0", 1));
	i = 0;
	while (n > 0)
	{
		rest = n % 16;
		if (rest < 10)
			hexadecimal[i] = rest + '0';
		else
			hexadecimal[i] = rest - 10 + c;
		i++;
		n = n / 16;
	}
	j = i - 1;
	while (j >= 0)
	{
		write(1, &hexadecimal[j], 1);
		j--;
	}
	return (i);
}
