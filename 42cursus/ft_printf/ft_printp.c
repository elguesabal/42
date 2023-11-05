/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:38:43 by joseanto          #+#    #+#             */
/*   Updated: 2023/11/05 18:18:11 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printp(unsigned long int n)
{
    int len;

    len = ft_prints("0x");
    len += ft_printx(n, 'a');
    return (len);
}