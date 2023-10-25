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

// #include <stdio.h>
#include <stddef.h>

// A função `strchr()` em C é usada para encontrar a primeira ocorrência de um
// caractere em uma string. Ela retorna um ponteiro para a primeira ocorrência
// do caractere na string ou NULL se o caractere não for encontrado.
char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (!c)
	{
		return ((char *)str);
	}
	return (NULL);
}

// int	main(void)
// {
// 	printf("return: %s", ft_strchr("teste", 's'));

// 	// // CODIGO PARA RETORNAR O ENDERECO DE MEMORIA DA PRIMEIRA OCORRENIA
// 	// char ch = 's', string[] = "teste";
// 	// char *pdest;
// 	// int result;

// 	// pdest = ft_strchr(string, ch );
//    	// result = (int)(pdest - string + 1);
//    	// if ( pdest != NULL )
//     //   		printf( "Result:   first %c found at position %d\n",
//					// ch, result );
//    	// else
//     //   		printf( "Result:   %c not found\n", ch );
//     // // CODIGO PARA RETORNAR O ENDERECO DE MEMORIA DA PRIMEIRA OCORRENIA
// 	return (0);
// }