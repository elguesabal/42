/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:37:58 by joseanto          #+#    #+#             */
/*   Updated: 2023/08/03 12:41:16 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*int	main()
{
	int	division;
	int	restDivision;

	ft_div_mod(10, 5, &division, &restDivision);

	printf("Resultado da divisao: %d\n", division);
        printf("Resto da divisao: %d\n", restDivision);
}*/
