/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:19:41 by joseanto          #+#    #+#             */
/*   Updated: 2023/08/13 11:42:33 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // retirar antes de mandar
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

// funcao q abre e le o arquivo "numbers.dict" e dps fecha
char	*open_file()
{
	int	file_description;

	// abertura do arquivo selecionado
	file_description = open("numbers.dict", O_RDONLY);

	// leitura do arquivo
	int	file_description2;
	char	*file_text;

	file_text = malloc(10000 * sizeof(char));
	file_description2 = read(file_description, file_text, 10000);

	// fechamento do arquivo
	close(file_description);
	close(file_description2);
	return file_text;
}

// funcao q converte string em numero (igual atoi)
int	function_atoi(char *number)
{
	int	i;
	int res;

	res = 0;
	i = 0;
	while (number[i] != '\0')
	{
		if (number[i] < '0' || number[i] > '9')
		{
			return (-1);
		}
		res = (res * 10) + (number[i] - '0');
		i++;
	}
	return res;
}

// funcao q combase no numero retorna um return do tipo char com o numero por extenso
char	*number_in_full(int int_number, char *char_number)
{
	char	*file_text = open_file();
	char	*result;
	// ...

	// ESPACO PARA COMCLUIR O PROGRAMA

	// ...
	result = "testeeeeeee";
	return result;
}

int	main(int argc, char *argv[])
{
	// armazenando o conteudo do arquivo "numbers.dict" no ponteiro file_text
	char	*file_text = open_file();

	// criei o int number q recebe o return da funcao function_atoi q converte string em inteiro
	int	number;

	// ponteiro q recebe a resposta com o numero em extenso
	char *result;

	if (argv[1])
		number = function_atoi(argv[1]); // se number for -1 e pq o argumento e invalido

	if (number < 1)
	{
		// entrada invalida
		write(1, "Error\n", 6);
	}
	else if (argc == 2)
	{
		// entrada padrao com apenas um argumento
		printf("argc == 2\n");
		
		result = number_in_full(number, argv[1]);
	}
	else if (argc == 3)
	{
		// dicionario padrao em ingles
		printf("argc == 3\n");
	}
	else if (argc == 3)
	{
		// dicionario bonus em portugues
		printf("argc == 3\n");
	}
}
