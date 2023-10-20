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




	size_t	i;

	while (str2[i])
	{
		i++;
	}
	if (!i) {
		return ((char *)str1);
	}
	while (*str1 && n >= i) {
		if (!strncmp(str1, str2, i)) {
			return (char *)str1;
		}
		str1++;
		i--;
	}
    return NULL;


}	// NAO TA PRONTO ESSA FUNCAO

int	main(void)
{
	printf("return: %s", ft_strnstr("testando o codigo de strnstr", "codigo", 20));
	return (0);
}