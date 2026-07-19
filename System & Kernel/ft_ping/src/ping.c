/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 18:37:48 by joseanto          #+#    #+#             */
/*   Updated: 2026/07/09 18:37:48 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ping.h"

/**
 * @author VAMPETA
 * @brief FUNCAO QUE INICIA E GERENCIA O PING
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
*/
void	start_ping(t_info *info)
{
	while (!stop_requested())
	{
		build_icmp(info);
		send_ping(info);
		if (receive_ping(info) == SUCCESS)
		{
			update_statistics(info);
			print_ping(info);
		}
		info->sequence++;
		sleep(1);
	}
}
