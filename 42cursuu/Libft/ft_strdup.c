/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:15:16 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/25 12:15:18 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>

// A função `strdup()` em C cria uma cópia dinamicamente alocada de uma string,
// incluindo o caractere nulo de terminação. Ela aloca memória suficiente para
// a nova string e copia o conteúdo da string original para a nova área
// de memória. É responsabilidade do programador liberar essa memória usando
//a função `free()` quando não for mais necessária.
char	*ft_strdup(const char *str)
{
	char	*str2;
	int		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	str2 = malloc(i * sizeof(char *));
	if (str2)
	{
		str2[i] = '\0';
		while (i)
		{
			i--;
			str2[i] = str[i];
		}
	}
	return (str2);
}

// int	main(void)
// {
// 	char	*str;

// 	str = ft_strdup("teste");
// 	printf("str: %s", str);
// 	free(str);
// 	return (0);
// }