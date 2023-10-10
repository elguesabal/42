/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:23:53 by joseanto          #+#    #+#             */
/*   Updated: 2023/08/16 12:36:45 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_sqrt(int nb)
{
	long int	number;

	number = 1;
	if (nb == 0)
	{
		return (0);
	}
	while (nb > number * number)
	{
		number++;
	}
	if (nb == number * number)
	{
		return (number);
	}
	return (0);
}
/*int	main(void)
{
	printf("%d", ft_sqrt(9));
}*/