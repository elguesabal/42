/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:20:40 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/25 18:20:42 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (n < 0)
		sign = 1;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i + sign);
}

static int	ft_sign(int n)
{
	if (n < 0)
	{
		return (n * -1);
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		aux;

	aux = n;
	i = ft_size(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i--;
	while (i >= 0)
	{
		if (i == 0 && n < 0)
			str[i] = '-';
		else
		{
			str[i] = ft_sign(aux % 10) + 48;
			aux = aux / 10;
		}
		i--;
	}
	str[ft_size(n)] = '\0';
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("return: %s", ft_itoa(123));
// 	return (0);
// }