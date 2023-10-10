/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:02:31 by joseanto          #+#    #+#             */
/*   Updated: 2023/08/15 20:37:43 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_factorial(int nb)
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
	number = nb;
	nb--;
	while (nb > 1)
	{
		number = number * nb;
		nb--;
	}
	return (number);
}
/*int main()
{
	printf("%d", ft_iterative_factorial(4));
}*/
