/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:11:01 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/27 09:11:03 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, (s + i));
		i++;
	}
}

// #include <stdio.h>

// static void upper(unsigned int i, char *str) {
// 	while (str[i])
// 	{
// 		if (str[i] >= 'a' && str[i] <= 'z')
// 		{
// 			str[i] -= 32;
// 		}
// 		i++;
// 	}
// }

// int main(void)
// {
// 	char	str[] = "teste";

// 	ft_striteri(str, upper);
// 	printf("%s", str);
// 	return (0);
// }