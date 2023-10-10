/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:49:03 by joseanto          #+#    #+#             */
/*   Updated: 2023/08/08 10:34:37 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	inverted[1000];
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i < size)
	{
		inverted[j] = tab[i];
		tab[i] = inverted[j];
		j--;
		i++;
	}
	i = 0;
	while (i < size)
	{
		tab[i] = inverted[i];
		j--;
		i++;
	}
}
/*int	main()
{
	int	numbers[5] = {1, 2, 3, 4, 5};
	printf("%d, %d, %d, %d, %d\n",
	numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
	ft_rev_int_tab(numbers, 5);
	printf("%d, %d, %d, %d, %d\n",
	numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
}*/
