/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:38:46 by joseanto          #+#    #+#             */
/*   Updated: 2023/08/15 20:55:56 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	number;

	if (nb < 0)
	{
		return (0);
	}
	else if (nb == 0)
	{
		return (1);
	}
	else if (nb > 2)
	{
		number = ft_recursive_factorial(nb - 1);
		number = number * nb;
		nb--;
		return (number);
	}
	else
	{
		return (nb);
	}
}
/*int	main(void)
{
	printf("%d", ft_recursive_factorial(4));
}*/