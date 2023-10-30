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

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char		*dest_p;
	const char	*src_p;

	if (!dest && !src)
		return (NULL);
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
	return (dest_p);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str1[50] = "testando o codigo", str2[50];

// 	ft_memmove(str2, str1, 8);
// 	printf("str2: %s", str2);
// 	return (0);
// }