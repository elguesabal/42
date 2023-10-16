/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:12:11 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/16 11:25:00 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalpha(int c)
{
	// if ((c > 64 && c < 91) || (c > 96 && c < 123))
	// {
	//	return (1);
	// }
	// return (0);
	return ((c > 64 && c < 91) || (c > 96 && c < 123));
}

int	main(void)
{
	printf("'&': %d\n", ft_isalpha('&'));
	printf("'A': %d", ft_isalpha('A'));
	printf("\n'a': %d", ft_isalpha('a'));
	return (0);
}
