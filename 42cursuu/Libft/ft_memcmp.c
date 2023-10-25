/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:53:26 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/20 15:53:28 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stddef.h>

// A função `memcmp()` em C compara duas áreas de memória byte a byte.
// Ela retorna um valor menor que zero se a primeira área de memória for menor
// que a segunda, zero se forem iguais ou um valor maior que zero se a primeira
// for maior que a segunda. É útil para comparar blocos de memória, como arrays
// ou estruturas de dados, em termos de ordem lexicográfica.
int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = ptr1;
	p2 = ptr2;
	while (n)
	{
		if (*p1 != *p2)
		{
			return (*p1 - *p2);
		}
		p1++;
		p2++;
		n--;
	}
	return (0);
}

// int main(void)
// {
//     printf("return: %d", ft_memcmp("a", "d", 1));
//     return (0);
// }