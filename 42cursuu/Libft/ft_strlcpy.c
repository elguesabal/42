/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:02:34 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/18 13:02:36 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stddef.h>

// A função `strlcpy()` em C é usada para copiar uma string de origem para um
// destino, limitando o número de caracteres copiados para evitar o estouro do
// buffer. Ela copia até um determinado número de caracteres da string de
// origem para o destino, garantindo que o destino seja devidamente terminado
// com um caractere nulo. Essa função é útil para evitar buffer overflows
// ao trabalhar com strings em C.
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		if (i < size)
		{
			dest[i] = src[i];
		}
		i++;
	}
	dest[size] = src[size];
	return (i);
}

// int	main(void)
// {
// 	char	str1[20] = "testando o codigo", str2[20];

// 	printf("Tamanho de str1: %ld\nstr2: %s", ft_strlcpy(str2, str1, 200), str2);
// 	return (0);
// }