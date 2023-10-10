/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:01:26 by joseanto          #+#    #+#             */
/*   Updated: 2023/08/08 13:04:03 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 65 || str[i] > 90)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/*int	main(void)
{
	char	str1[] = "VAMPETA";
	int	return1;
	char	str2[] = "vampeta";
	int	return2;

	return1 = ft_str_is_uppercase(str1);
	printf("str1: %s\n", str1);
	printf("return1: %d\n", return1);

	return2 = ft_str_is_uppercase(str2);
	printf("str2: %s\n", str2);
	printf("return2: %d\n", return2);
}*/