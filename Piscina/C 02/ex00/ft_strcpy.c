/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:30:29 by joseanto          #+#    #+#             */
/*   Updated: 2023/08/14 10:20:55 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*int	main(void)
{
	char	str1[50] = "vampeta";
	char	str2[50];
	char	*dest;
	
	dest = ft_strcpy(str2, str1);
	printf("Valor de dest: %s\n", dest);

	// ft_strcpy(str2, str1);
	printf("Valor de str2 apos a funcao: %s\n", str2);
}*/
