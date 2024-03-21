/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:22:00 by joseanto          #+#    #+#             */
/*   Updated: 2024/03/21 14:23:20 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	verification(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (printf("Error\nNumero de argumentos invalidos\n"));
	if (argv[1][0] == '\0' || argv[1][0] == '0' || is_number(argv[1]))
		return (printf("Error\nNumero de filosofos invalido\n"));
	if (argv[2][0] == '\0' || argv[2][0] == '0' || is_number(argv[2]))
		return (printf("Error\nNumero para morrer em ms invalido\n"));
	if (argv[3][0] == '\0' || argv[3][0] == '0' || is_number(argv[3]))
		return (printf("Error\nNumero para comer em ms invalido\n"));
	if (argv[4][0] == '\0' || argv[4][0] == '0' || is_number(argv[4]))
		return (printf("Error\nNumero para dormir em ms invalido\n"));
	if (argc == 6 && (argv[5][0] == '\0' || argv[5][0] == '0' || is_number(argv[5])))
		return (printf("Error\nNumero de repeticoes invalido\n"));
	return (0);
}
