/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:10:02 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/18 10:10:04 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *str, int c, size_t size)
{
	char		*str_p;

	str_p = str;
	while (size--)
	{
		*str_p++ = (char)c;
	}
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str[10];

// 	ft_memset(str, '*', 10);
// 	printf("str: %s", str);
// 	return (0);
// }