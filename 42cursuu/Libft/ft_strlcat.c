/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:21:29 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/18 15:21:32 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] && i < size)
	{
		i++;
	}
	j = 0;
	while (src[j])
	{
		if (i < size - 1)
		{
			dest[i] = src[j];
			i++;
		}
		j++;
	}
	dest[i + 1] = '\0';
	return (i);
}

//#include <stdio.h>

// int	main(void)
// {
// 	char	str1[20] = "testando ", str2[] = "o codigo";

// 	printf("Tamanho da nova string: %ld\nstr1: %s", 
// 	ft_strlcat(str1, str2, sizeof(str1)), str1);
// 	return (0);
// }