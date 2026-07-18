/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 13:14:58 by joseanto          #+#    #+#             */
/*   Updated: 2026/07/14 11:32:33 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ping.h"

/**
 * @author VAMPETA
 * @brief CALCULA O CHECKSUM PARA GARANTIA DE INTEGRIDADE
 * @param data PONTEIRO PARA O INICIO DA MENSAGEM ICMP
 * @param len TAMANHO DA MENSAGEM ICMP EM BYTES
 * @return CALCULO DO CHECKSUM PARA SER ARMAZENADO NO CABECALHO ICMP
*/
uint16_t	checksum(void *data, size_t len)
{
	uint32_t	sum;
	uint16_t	*ptr;

	sum = 0;
	ptr = data;
	while (len > 1)
	{
		sum += *ptr++;
		len -= 2;
	}
	if (len == 1)
		sum += *(uint8_t *)ptr;
	while (sum >> 16)
		sum = (sum & 0XFFFF) + (sum >> 16);
	return ((uint16_t) ~ sum);
}
