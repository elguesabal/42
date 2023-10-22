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

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char	*destP;
	unsigned const char	*srcP;

	destP = dest;
	srcP = src;
	while (size--)
	{
		*destP++ = *srcP++;
	}
}

int	main(void)
{
	char	str1[50] = "testando o codigo", str2[50];

	ft_memcpy(str2, str1, 8);
	printf("str2: %s", str2);

	// ft_memcpy(str1, str1 + 11, 6);
	// printf("str1: %s", str1);
	return (0);
}
