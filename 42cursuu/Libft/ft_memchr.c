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

#include <stdio.h>

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	const unsigned char *charPtr;
	unsigned char charC;

	charPtr = ptr;
	charC = (unsigned char)c;
	while (n)
	{
		if (*charPtr == charC)
		{
			return ((void*)charPtr);
		}
		charPtr++;
		n--;
	}
	return (NULL);
}

int	main(void)
{
	printf("return: %s", (char *)ft_memchr("testando", 97, 8));
	return (0);
}
