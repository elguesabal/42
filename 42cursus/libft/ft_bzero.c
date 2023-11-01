/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:06:41 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/18 10:06:42 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *str, size_t size)
{
	char	*str_p;

	str_p = str;
	while (size--)
	{
		*str_p++ = 0;
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str[10];

// 	ft_bzero(str, 10);
// 	printf("%s", str);
// 	return (0);
// }