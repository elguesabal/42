/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:35:45 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/25 11:35:54 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	if (!str)
		return (NULL);
	while (i >= 0)
	{
		if (str[i] == c)
		{
			return ((char *)(str + i));
		}
		i--;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("return: %s\n\n", ft_strrchr("teste", '\0'));
// 	return (0);
// }