/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:28:22 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/20 14:28:24 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	const unsigned char	*char_ptr;
	unsigned char		char_c;

	char_ptr = ptr;
	char_c = (unsigned char)c;
	while (n)
	{
		if (*char_ptr == char_c)
		{
			return ((void *)char_ptr);
		}
		char_ptr++;
		n--;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("return: %s", (char *)ft_memchr("testando", 97, 8));
// 	return (0);
// }