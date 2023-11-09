/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:38:43 by joseanto          #+#    #+#             */
/*   Updated: 2023/11/09 10:33:10 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printp(unsigned long long n)
{
	if (!n)
		return (ft_prints("(nil)"));
	return (ft_prints("0x") + ft_printx(n, 'a'));
}
