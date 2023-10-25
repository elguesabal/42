/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:28:22 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/20 14:28:24 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stddef.h>

// A função `memchr()` em C é usada para encontrar a primeira ocorrência de um
// byte específico em uma área de memória. Ela retorna um ponteiro para o
// primeiro byte correspondente encontrado ou NULL se o byte não for encontrado.
void	*ft_memchr(const void *ptr, int c, size_t n)
{
	const unsigned char	*char_ptr;
	unsigned char		char_c;

	char_ptr = ptr;
	char_c = (unsigned char)c;
	while (n)
	{
		if (*char_ptr == char_c)
		{
			return ((void *)char_ptr);
		}
		char_ptr++;
		n--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	printf("return: %s", (char *)ft_memchr("testando", 97, 8));
// 	return (0);
// }