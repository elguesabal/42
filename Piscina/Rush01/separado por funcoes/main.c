/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:58:23 by joseanto          #+#    #+#             */
/*   Updated: 2023/08/05 18:19:18 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main()
{
	// simulei o recebimento dos argumentos da funcao

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









	int	i;
	int	j;

	// comecei a criar a primeira matriz com o malloc
	int	**dicas;

	// cria um array com 4 posicoes
	dicas = malloc(4 * sizeof(int*));

	// cria 4 arrays que recebem arrays com 4 posicoes
	i = 0;
	while (i < 4)
	{
		dicas[i] = malloc(4 * sizeof(int));
		i++;
	}

	// dei valor a cada posicao com o argumento passado pela funcao
	
	// cima
	dicas[0][0] = col1up;
	dicas[0][1] = col2up;
	dicas[0][2] = col3up;
	dicas[0][3] = col4up;

	// baixo
	dicas[1][0] = col1down;
	dicas[1][1] = col2down;
	dicas[1][2] = col3down;
	dicas[1][3] = col4down;

	// esqueda
	dicas[2][0] = row1left;
	dicas[2][1] = row2left;
	dicas[2][2] = row3left;
	dicas[2][3] = row4left;

	// direita
	dicas[3][0] = row1right;
	dicas[3][1] = row2right;
	dicas[3][2] = row3right;
	dicas[3][3] = row4right;


	// comecei a criar a segunda matriz com o malloc
	int	**resposta;

	// cria um array com 4 posicoes
	resposta = malloc(4 * sizeof(int*));

	// cria 4 arrays que recebem arrays com 4 posicoes
	i = 0;
	while (i < 4)
	{
		resposta[i] = malloc(4 * sizeof(int));
		i++;
	}

	// dei valor a cada posicao com o argumento passado pela funcao
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			resposta[i][j] = 0;
			j++;
		}
		i++;
	}















	// printa a matriz de dicas completa
	i = 0;
	while (i != 4)
	{
		j = 0;
		while (j != 4)
		{
			printf("%d", dicas[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	printf("\n\n");

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
