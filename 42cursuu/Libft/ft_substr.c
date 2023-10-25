/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:22:13 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/25 13:22:15 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	str = malloc((len - start) * sizeof(char *));
	if (str)
	{
		i = 0;
		while (start < len)
		{
			*(str + i++) = s[start];
			start++;
		}
		str[i] = '\0';
	}
	return (str);
}

// int	main(void)
// {
// 	printf("\nreturn: %s", ft_substr("teste", 2, 5));
// 	return (0);
// }