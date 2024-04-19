/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:23:24 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/18 18:23:25 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (!c)
	{
		return ((char *)str);
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("return: %s", ft_strchr("teste", 's'));
// 	return (0);
// }
