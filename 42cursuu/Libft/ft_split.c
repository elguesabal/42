/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:48:23 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/23 09:48:33 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// CONTA QUANTOS CARACTERES TEM NA STRING
static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

// CONTA QUANTOS CARACTERES SEPARADORES TEM
static size_t	ft_character(const char *str, const char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
		{
			i++;
		}
		str++;
	}
	return (i);
}

// CONTA QUANTOS CARACTERES TEM NO INTERVALO DE CADA CARATER
static int	ft_len_substr(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
	{
		i++;
	}
	return (i);
}

// ABRE ESPACO PARA CADA SUBSTRING SEPARADA
static char	**ft_mat_malloc(int n_character, char const *s, char c)
{
	char	**mat;
	int	i, j;

	mat = malloc((n_character + 2) * sizeof(char *));
	mat[n_character + 1] = NULL;
	i = 0;
	j = 0;
	while (n_character >= 0)
	{
		i += ft_len_substr(s, c);
		mat[n_character] = malloc((i - j) * sizeof(char));
		j += ft_len_substr(s, c);
		n_character--;
	}
//	if (mat)	//USEI PRA TESTES TUDO Q TA COMENTADO
//	{
//		printf("\n\nta retornando null\n\n");
//	}
//	mat[0][0] = 'q';
//	printf("\n\nta retornando %c\n\n", mat[0][0]);
	return (mat);
}

char	**ft_split(char const *s, char c)
{
	char	**mat;
	int	s_len, n_character, i, j, bef_len, init_len, next_len;

	s_len = ft_strlen(s);// CONTA QUANTOS CARACTERES TEM NA STRING
	n_character = ft_character(s, c);// CONTA QUANTOS CARACTERES SEPARADORES TEM
	mat = ft_mat_malloc(n_character, s, c);// ABRE ESPACO PARA CADA SUBSTRING SEPARADA

	bef_len = 0;
	//init_len = 0;
	next_len = 0;
	j = ft_strlen(s) - 1;
	while (n_character >= 0)
	{
		bef_len += ft_len_substr(s, c);
//		init_len = bef_len - next_len;
		i = bef_len - next_len - 1;
		next_len += ft_len_substr(s, c);

		mat[n_character][i + 1] = '\0';
		while (i >= 0 && s[j])
		{
printf("%d ", j);
			mat[n_character][i] = s[j];
//			init_len--;
			j--;
			i--;
		}
printf("\n");
		n_character--;
	}
	return (mat);
}

int	main(void) // NAO TERMINEI
{
	char	**mat;
	int	i, j;

	mat = ft_split("micro-onda", '-');	
	i = 0;
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
		{
			printf("%c", mat[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	free(mat);
	return (0);
}
