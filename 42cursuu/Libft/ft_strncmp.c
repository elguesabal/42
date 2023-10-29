/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:14:52 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/20 12:14:54 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
	{
		return (0);
	}
	while (n && *str1 && *str2)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
		n--;
	}
	return (*str1 - *str2);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("return: %d", ft_strncmp("bbc", "abc", 3));
// 	return (0);
// }