/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:25:12 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/25 13:25:15 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int	len1;
	int	len2;
	int	i;

	len1 = 0;
	len2 = 0;
	while (s1[len1])
	{
		len1++;
	}
	while (s2[len2])
	{
		len2++;
	}
	new_str = malloc((len1 + len2 + 1) * sizeof(char *));
	if (new_str)
	{
		new_str[len1 + len2] = '\0';
		while (len2)
		{
			len2--;
			new_str[len1 + len2] = s2[len2];
		}
		while (len1)
		{
			len1--;
			new_str[len1] = s1[len1];
		}
	}
	return (new_str);
}

// int	main(void)
// {
// 	printf("return: %s", ft_strjoin("testando", " o codigo"));
// 	return(0);
// }