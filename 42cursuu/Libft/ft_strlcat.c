/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:21:29 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/18 15:21:32 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stddef.h>

// A função `strlcat()` em C é usada para concatenar duas strings, garantindo
// que o destino tenha espaço suficiente para acomodar os caracteres da
// concatenação. Ela adiciona caracteres da string de origem ao final da string
// de destino, limitando o número de caracteres copiados para evitar estouro de
// buffer. A função também garante que o destino seja devidamente terminado com
// um caractere nulo após a concatenação.
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] && i < size)
	{
		i++;
	}
	j = 0;
	while (src[j])
	{
		if (i < size - 1)
		{
			dest[i] = src[j];
			i++;
		}
		j++;
	}
	dest[i + 1] = '\0';
	return (i);
}

// int	main(void)
// {
// 	char	str1[20] = "testando ", str2[] = "o codigo";

// 	printf("Tamanho da nova string: %ld\nstr1: %s", 
// 	ft_strlcat(str1, str2, sizeof(str1)), str1);
// 	return (0);
// }