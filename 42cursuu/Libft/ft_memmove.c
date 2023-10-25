/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:12:15 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/18 11:12:17 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stddef.h>

// A função `memmove()` em C é usada para copiar uma quantidade específica de
// bytes de uma área de memória para outra, mesmo que as áreas de origem e
// destino se sobreponham. Isso a diferencia da função `memcpy()`, que não
// lida bem com sobreposição de memória. A `memmove()` garante a cópia
// segura e correta dos dados, mesmo quando as áreas de origem e destino
// estão em conflito.
void	ft_memmove(void *dest, const void *src, size_t size)
{
	char		*dest_p;
	const char	*src_p;

	dest_p = dest;
	src_p = src;
	if (dest_p < src_p)
	{
		while (size--)
		{
			*dest_p++ = *src_p++;
		}
	}
	else
	{
		dest_p += size;
		src_p += size;
		while (size--)
		{
			*(--dest_p) = *(--src_p);
		}
	}
}

// int	main(void)
// {
// 	char	str1[50] = "testando o codigo", str2[50];

// 	ft_memmove(str2, str1, 8);
// 	printf("str2: %s", str2);

// 	// ft_memmove(str1, str1 + 11, 6);
// 	// printf("str1: %s", str1);
// 	return (0);
// }