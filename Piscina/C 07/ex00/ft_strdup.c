/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:35:20 by joseanto          #+#    #+#             */
/*   Updated: 2023/08/11 11:47:11 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdlib.h>
#include <stdio.h>*/

char	*ft_strdup(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}

	char	*str;
	
	str = malloc(i * sizeof(char*));

	i = 0;
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}
/*int	main(void)
{
	char	src[] = "vampeta";
	char	*duplicate = ft_strdup(src);

	printf("%s", duplicate);
}*/