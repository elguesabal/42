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

int	ft_isalnum(int c)
{
	return ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123));
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("'a': %d\n", ft_isalnum('a'));
// 	return (0);
// }