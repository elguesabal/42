/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:58:23 by joseanto          #+#    #+#             */
/*   Updated: 2023/08/05 13:48:03 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main()
{
	// cima
	int	col1up = 4;
	int	col2up = 3;
	int	col3up = 2;
	int	col4up = 1;

	// baixo
	int	col1down = 1;
	int	col2down = 2;
	int	col3down = 2;
	int	col4down = 2;

	// esquerda
	int	row1left = 4;
	int	row2left = 3;
	int	row3left = 2;
	int	row4left = 1;

	// direita
	int	row1right = 1;
	int	row2right = 2;
	int	row3right = 2;
	int	row4right = 2;


	// matriz com todas as dicas
	int	dicas[4][4] =
	{
		{col1up, col2up, col3up, col4up},
		{col1down, col2down, col3down, col4down},
		{row1left, row2left, row3left, row4left},
		{row1right, row2right, row3right, row4right},
	};


	// matriz que vai receber a resposta final
	int	resposta[4][4] = 
	{
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	// testar quais dicas sao 1 para poder dar valor 4
	int	i = 0;
	int	j = 0;
	while (i != 4)
	{
		j = 0;
		while (j != 4)
		{
			if (dicas[i][j] == 1)
			{
				resposta[i][j] = 4;
			}
			j++;
		}
		i++;
	}

//	printf("%d", dicas[1][3]);
// 	printf("%d", dicas[1][2]);


	// printa a matriz de resposta completa
	i = 0;
	while (i != 4)
	{
		j = 0;
		while (j != 4)
		{
			printf("%d", resposta[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
