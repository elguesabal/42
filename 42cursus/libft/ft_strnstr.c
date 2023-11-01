/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:15:18 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/20 16:15:24 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len_str2;

	if (str2[0] == '\0')
		return ((char *)str1);
	if (n == 0)
		return (NULL);
	i = 0;
	j = 0;
	len_str2 = ft_strlen(str2);
	while (str1[i] && i < n)
	{
		while (str1[i + j] == str2
			[j] && i + j < n && str1[i + j] != '\0')
			j++;
		if (j == len_str2)
			return ((char *)(str1 + i));
		j = 0;
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("return: %s", ft_strnstr("testando o codigo de strnstr",
// 	"codigo", 20));
// 	return (0);
// }