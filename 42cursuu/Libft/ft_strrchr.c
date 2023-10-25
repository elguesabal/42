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

// #include <stdio.h>

// A função `strrchr()` em C é usada para encontrar a última ocorrência de um
// caractere em uma string. Ela retorna um ponteiro para a última ocorrência do
// caractere na string ou NULL se o caractere não for encontrado.
char	*ft_strrchr(const char *str, int c)
{
	const char	*result;

	while (*str)
	{
		if (*str == c)
		{
			result = str;
		}
		str++;
	}
	return ((char *)result);
}

// int	main(void)
// {
// 	printf("return: %s\n\n", ft_strrchr("teste", 't'));
// 	return (0);
// }