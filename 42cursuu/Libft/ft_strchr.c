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

#include <stdio.h>

char	*ft_strchr(const char *str, int c)
{
	//int	i;

	//i = 0;
	//while (str[i])
	//{
	//	if (str[i] == c)
	//	{
	//		return ((char *)str + i);
	//	}
	//	i++;
	//}
	//return (NULL);

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

int	main(void)
{
	char	str[] = "teste", c = 's';
	
	printf("return: %s\n\n", ft_strchr(str, c));



	// // CODIGO PARA RETORNAR O ENDERECO DE MEMORIA DA PRIMEIRA OCORRENIA
	// char ch = 's', string[] = "teste";
	// char *pdest;
	// int result;
	
	// pdest = ft_strchr(string, ch );
   	// result = (int)(pdest - string + 1);
   	// if ( pdest != NULL )
    //   		printf( "Result:   first %c found at position %d\n", ch, result );
   	// else
    //   		printf( "Result:   %c not found\n", ch );
    // // CODIGO PARA RETORNAR O ENDERECO DE MEMORIA DA PRIMEIRA OCORRENIA
	
	
	return (0);
}
