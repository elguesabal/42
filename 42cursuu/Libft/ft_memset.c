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

// #include <stdio.h>
#include <stddef.h>

// A função `memset()` em C é usada para preencher uma área de memória com um
// valor específico. Ela recebe um ponteiro para a área de memória, o valor a
// ser preenchido e o número de bytes a serem preenchidos.
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

// int	main(void)
// {
// 	char	str[10];

// 	ft_memset(str, '*', 10);
// 	printf("str: %s", str);
// 	return (0);
// }