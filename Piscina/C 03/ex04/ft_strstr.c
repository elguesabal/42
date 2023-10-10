/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:39:32 by joseanto          #+#    #+#             */
/*   Updated: 2023/08/09 13:10:38 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && to_find[j] != '\0')
	{
		if (to_find[j] == str[i])
		{
			j++;
		}
		else
		{
			j = 0;
		}
		i++;
	}
	if (to_find[j] == '\0')
	{
		return (&str[i - j]);
	}
	return (0);
}
/*int	main(void)
{
	char	str[] = "vampeta";
	char	to_find[] = "vap";

	char	*result = ft_strstr(str, to_find);

	printf("result: %s", result);
}*/