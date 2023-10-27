/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:54:27 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/16 15:54:31 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stddef.h>

// A função `strlen()` em C é usada para calcular o comprimento de uma string,
// ou seja, o número de caracteres na string, excluindo o caractere nulo `\0`
// de terminação.
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	printf("teste: %ld", ft_strlen("teste"));
// 	return (0);
// }