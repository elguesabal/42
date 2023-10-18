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

#include <stdio.h>

void	*ft_memset(void *str, int c, size_t size)
{
	unsigned char	*strP;
	
	strP = str;	// REVISAR ESSA POHA
	while (size--)
	{
		*strP++ = (unsigned char)c;
	}
}

int	main(void)
{
	char	str[10];

	ft_memset(str, '*', 10);
	printf("str: %s", str);
	return (0);
}
