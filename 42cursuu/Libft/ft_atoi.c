/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:44:20 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/20 17:44:22 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *str)
{
	int sign, result;

	result = 0;
	sign = 1;
	while (*str == 32)
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && *str > 47 && *str < 58)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}

int	main(void)
{
	printf("return: %d", ft_atoi("-12345"));
	return (0);
}