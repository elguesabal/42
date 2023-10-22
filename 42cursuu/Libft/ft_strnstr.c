/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:15:18 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/20 16:15:24 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h> // tirar isso e fazer a funcao strncmp

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
//	int	i;
//
//	while (n && str1)
//	{
//		i = 0;
//		while (str1[i] == str2[i])
//		{
//			if (str2[i] == '\0')
//			{
//				return (str1[i]);
//			}
//			i++;
//		}
//		str1++;
//		str2++;
//		n--;
//	}




	// size_t	i;

	// while (str2[i])
	// {
	// 	i++;
	// }
	// if (!i) {
	// 	return ((char *)str1);
	// }
	// while (*str1 && n >= i) {
	// 	if (!strncmp(str1, str2, i)) {
	// 		return (char *)str1;
	// 	}
	// 	str1++;
	// 	i--;
	// }
    // return NULL;



	int	i;

	if (!*str2) {
		return ((char *)str1);
	}
    while (*str1 && n > 0) {
        while (*str2 && str1[i] == str2[i] && n > 0) {
            str1[i++];
            str2[i++];
            n--;
        }
        if (!str2[i]) {
            return ((char *)str1);
        }
        str1++;
        n--;
    }
    return (NULL);
}	// NAO TA PRONTO ESSA FUNCAO // REVISAR DNV DEPOIS


char *strnstr(const char *haystack, const char *needle, size_t len) {
    if (*needle == '\0') {
        return (char *)haystack;
    }

    while (*haystack != '\0' && len > 0) {
        const char *h = haystack;
        const char *n = needle;

        // Compara os caracteres em haystack e needle
        while (*n != '\0' && *h == *n && len > 0) {
            h++;
            n++;
            len--;
        }

        // Se a substring foi encontrada, retorna um ponteiro para o início dela
        if (*n == '\0') {
            return (char *)haystack;
        }

        // Move para o próximo caractere em haystack
        haystack++;
        len--;
    }

    // Substring não encontrada
    return NULL;
}

int	main(void)
{
	printf("return: %s", ft_strnstr("testando o codigo de strnstr", "codigo", 20));
	return (0);
}