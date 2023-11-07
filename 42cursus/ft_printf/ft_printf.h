/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:43:35 by joseanto          #+#    #+#             */
/*   Updated: 2023/11/07 11:45:01 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_printc(const char c);
int	ft_prints(char *str);
int	ft_printp(unsigned long long n);
int	ft_printd(int n);
int	ft_printu(unsigned int n);
int	ft_printx(unsigned long long n, const char c);

#endif