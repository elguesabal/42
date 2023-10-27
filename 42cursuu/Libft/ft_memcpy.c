/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:53:19 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/18 10:53:21 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stddef.h>

// A função `memcpy()` em C é usada para copiar um bloco de memória de uma
// origem para um destino. Ela copia um número específico de bytes da área de
// memória de origem para a área de memória de destino, permitindo a cópia
// eficiente de dados entre diferentes variáveis ou estruturas de dados.
void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t		i;
	char		*d;
	char		*s;

	if (!dest && !src)
		return (NULL);
	i = 0;
	d = (char *)dest;
	s = (char *)src;
	while (i < size)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	str1[50] = "testando o codigo", str2[50];

// 	ft_memcpy(str2, str1, 8);
// 	printf("str2: %s", str2);

// 	// ft_memcpy(str1, str1 + 11, 6);
// 	// printf("str1: %s", str1);
// 	return (0);
// }