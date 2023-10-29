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

#include <stddef.h>

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (!*str2)
	{
		return ((char *)str1);
	}
	while (*str1 && n > 0)
	{
		while (*str2 && str1[i] == str2[i] && n > 0)
		{
			i++;
			n--;
		}
		if (!str2[i])
		{
			return ((char *)str1);
		}
		str1++;
		n--;
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