/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:46:28 by joseanto          #+#    #+#             */
/*   Updated: 2023/10/16 15:46:30 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

// A função isprint() em C verifica se um caractere é imprimível (ou seja, um
// caractere que pode ser exibido na tela, excluindo caracteres de controle) e
// retorna verdadeiro (diferente de zero) se for, e falso (zero) caso contrário.
int	ft_isprint(int c)
{
	return (c > 31 && c < 127);
}

// int	main(void)
// {
// 	printf("'a': %d", ft_isprint('a'));
// 	printf("\n'\t (tab)': %d", ft_isprint('\t'));
// 	printf("\n'': %d", ft_isprint(''));
// 	return (0);
// }