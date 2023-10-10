/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:11:53 by joseanto          #+#    #+#             */
/*   Updated: 2023/08/14 10:15:55 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/*int	main(void)
{
	char 	str1[] = "vampeta";
	char 	str2[] = "vampeta123";
	char 	str3[] = "";

	int res1 = ft_str_is_alpha(str1);
	int res2 = ft_str_is_alpha(str2);
	int res3 = ft_str_is_alpha(str3);
	printf("return: %d\n", res1);
	printf("return: %d\n", res2);
	printf("rertun: %d\n", res3);
}*/
