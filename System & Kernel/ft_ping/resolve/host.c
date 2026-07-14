/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   host.c                                             :+:      :+:    :+:   */
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
 * @brief RESOLVE O HOST TRANSFORMANDO ELE EM ENDERECO IP E SALVANDO ADDR
 * @param info ENDERECO DE MEMORIA RESPOSNSAVEL PELAS INFORMACOES DO PROGRAMA
*/
void	resolve_host(t_info *info)
{
	struct addrinfo		hints;
	struct addrinfo		*result;
	int					status;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_RAW;
	hints.ai_protocol = IPPROTO_ICMP;
	status = getaddrinfo(info->host, NULL, &hints, &result);
	if (status != 0)
	{
		printf("ft_ping: %s: %s\n", info->host, gai_strerror(status));
		return ;
	}
	info->addr = *(struct sockaddr_in *)result->ai_addr;
	if (inet_ntop(AF_INET, &info->addr.sin_addr, info->ip, sizeof(info->ip)) == NULL)
	{
		freeaddrinfo(result);
		exit(1);
	}
	freeaddrinfo(result);
}
