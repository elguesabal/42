/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:06:41 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/18 10:06:42 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stddef.h>

// A função `bzero()` em C é usada para definir um bloco de memória como zero,
// ou seja, preenche a área de memória com zeros. É semelhante à função
// `memset()`, mas é especialmente usada para definir a memória como zero.
// No entanto, é importante notar que `bzero()` foi marcada como obsoleta em
// muitos sistemas e a recomendação é usar `memset()` para operações similares.
void	ft_bzero(void *str, size_t size)
{
	unsigned char	*str_p;

	str_p = str;
	while (size--)
	{
		*str_p++ = '0';
	}
	*str_p = '\0';
}

// int	main(void)
// {
// 	char	str[10];

// 	ft_bzero(str, 10);
// 	printf("%s", str);
// 	return (0);
// }