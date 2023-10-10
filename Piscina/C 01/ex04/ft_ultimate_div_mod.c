/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:27:34 by joseanto          #+#    #+#             */
/*   Updated: 2023/08/07 09:42:52 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	temp = *a / *b;
	*b = *a % *b;
	*a = temp;
}
	/* passar isto para a funcao ft_ultimate_div_mod
	printf("Valor do ponteiro a: %d\n", *a);
	printf("Valor do ponteiro b: %d\n\n", *b);
	printf("Endereco do ponteiro a: %p\n", a);
	printf("Endereco do ponteiro b: %p\n", b);*/
/*int	main()
{
	int	division = 10;
	int	restDivision = 5;

	ft_ultimate_div_mod(&division, &restDivision);
}*/
