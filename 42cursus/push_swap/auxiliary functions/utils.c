/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:13:33 by joseanto          #+#    #+#             */
/*   Updated: 2024/01/26 14:19:46 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atoi(const char *str)
{
	int	sign;
	long	result;

	result = 0;
	sign = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == 43)
		str++;
	while (*str && *str > 47 && *str < 58)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}

// void	ft_putstr(char *str)
// {
// 	int	i;

// 	if (!str)
// 	{
// 		write(1, "(null)", 6);
// 		return ;
// 	}
// 	i = 0;
// 	while (str[i])
// 		i += write(1, &str[i], 1);
// }

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += write(1, "-", 1);
		i += write(1, "2", 1);
		i += ft_putnbr(147483648);
		return (i);
	}
	if (n < 0)
	{
		i += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
	{
		n += 48;
		i += write(1, &n, 1);
	}
	return (i);
}