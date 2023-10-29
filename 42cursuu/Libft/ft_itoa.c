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

#include <stdlib.h>

static int	size_n(int n, int i)
{
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_sign(int *sign, int *n, int *i)
{
	*sign = 1;
	*n *= -1;
	++*i;
}

char	*ft_itoa(int n)
{
	int		sign;
	int		i;
	int		copy;
	char	*str;

	sign = 0;
	i = 0;
	if (n < 0)
		ft_sign(&sign, &n, &i);
	copy = n;
	i = size_n(n, i);
	str = malloc((i + sign + 1) * sizeof(char));
	if (str)
	{
		str[i] = '\0';
		while (i--)
		{
			n = n / 10;
			str[i] = 48 + copy - n * 10;
			copy = copy / 10;
		}
		if (str[0] == '0')
			str[0] = '-';
	}
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("return: %s", ft_itoa(-52304));
// 	return (0);
// }