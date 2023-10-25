/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:05:07 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/16 15:05:09 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

// A função isalnum() em C verifica se um caractere é uma letra (maiúscula ou
// minúscula) ou um dígito (0 a 9) e retorna verdadeiro (diferente de zero)
// se for, e falso (zero) caso contrário.
int	ft_isalnum(int c)
{
	return ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123));
}

// int	main(void)
// {
// 	printf("'a': %d\n", ft_isalnum('a'));
// 	printf("'5': %d", ft_isalnum('5'));
// 	printf("\n'*': %d", ft_isalnum('*'));
// 	return (0);
// }