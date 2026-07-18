/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 17:02:57 by joseanto          #+#    #+#             */
/*   Updated: 2026/07/17 17:02:57 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ping.h"

static volatile sig_atomic_t	g_stop = 0;

/**
 * @author VAMPETA
 * @brief FUNCAO CHAMADA AO RECEBER UM SINAL
 * @param sig SINAL RECEBIDO
*/
void	stop_ping(int sig)
{
	(void)sig;
	g_stop = 1;
}

/**
 * @author VAMPETA
 * @brief FUNCAO CRIADA PARA RETORNAR O VALOR DA VARIAVEL g_stop
 * @return RETORNA g_stop
*/
int	stop_requested(void)
{
	return (g_stop);
}
