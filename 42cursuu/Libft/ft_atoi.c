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

// #include <stdio.h>

// A função `atoi()` em C converte uma string que representa um número
// inteiro em um valor inteiro correspondente. Ela retorna o valor inteiro
// representado pela string, ou zero se a string não puder ser convertida
// em um inteiro válido.
int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

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

// int	main(void)
// {
// 	printf("return: %d", ft_atoi("-12345"));
// 	return (0);
// }