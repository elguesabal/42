/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:43:35 by joseanto          #+#    #+#             */
/*   Updated: 2023/11/05 18:37:35 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINT_H
# define LIBFTPRINT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_printc(const char c);
int	ft_prints(char *str);
int ft_printp(unsigned long int n);
int	ft_printd(int n);
int	ft_printu(unsigned int n);
int	ft_printx(unsigned int n, const char c);

#endif