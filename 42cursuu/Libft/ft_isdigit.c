/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:41:16 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/16 14:41:17 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

// A função isdigit() em C verifica se um caractere é um dígito (0 a 9) e
// retorna verdadeiro (diferente de zero) se for, e falso (zero) caso
// contrário.
int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

// int	main(void)
// {
// 	printf("'5': %d\n", ft_isdigit('5'));
// 	printf("'a': %d", ft_isdigit('a'));
// 	return (0);
// }