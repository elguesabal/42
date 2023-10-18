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

#include <stdio.h>

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
//printf("%c", str[i]);
			return ((char *)c);
		}
		i++;
	}
	return (NULL);
}

int	main(void)
{
	char	str[] = "teste", c = 's';
ft_strchr(str, c);
	// printf("return: %c", ft_strchr(str, c));
	return (0);
}