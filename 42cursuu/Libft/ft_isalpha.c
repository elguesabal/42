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

// #include <stdio.h>

// A função isalpha() em C verifica se um caractere é uma letra do alfabeto
// (maiúscula ou minúscula) e retorna verdadeiro (diferente de zero) se for,
//e falso (zero) caso contrário.
int	ft_isalpha(int c)
{
	return ((c > 64 && c < 91) || (c > 96 && c < 123));
}

// int	main(void)
// {
// 	printf("'&': %d\n", ft_isalpha('&'));
// 	printf("'A': %d", ft_isalpha('A'));
// 	printf("\n'a': %d", ft_isalpha('a'));
// 	return (0);
// }