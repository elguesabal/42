/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:16:08 by joseanto          #+#    #+#             */
/*   Updated: 2023/08/15 21:27:40 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	number;

	if (power < 0)
	{
		return (0);
	}
	else if (power == 0)
	{
		return (1);
	}
	else if (power > 1)
	{
		number = ft_recursive_power(nb, power - 1);
		number = number * nb;
		power--;
		return (number);
	}
	else
	{
		return (nb);
	}
}
/*int	main(void)
{
	printf("%d", ft_recursive_power(4, 5));
}*/