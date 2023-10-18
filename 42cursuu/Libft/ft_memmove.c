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

#include <stdio.h>

void	ft_memmove(void *dest, const void *src, size_t size)
{
	char	*destP = dest;
	const char	*srcP = src;

	if (destP < srcP)
	{
		while (size--)
		{
			*destP++ = *srcP++;
		}
	}
	else
	{
		destP += size;
		srcP += size;
		while (size--)
		{
			*(--destP) = *(--srcP);
		}
	}

}

int	main(void)
{
	char	str1[50] = "testando o codigo", str2[50];

	ft_memmove(str2, str1, 8);
	printf("str2: %s", str2);
	
	// ft_memmove(str1, str1 + 11, 6);
	// printf("str1: %s", str1);
	return (0);
}
