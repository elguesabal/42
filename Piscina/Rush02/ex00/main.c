/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:19:41 by joseanto          #+#    #+#             */
/*   Updated: 2023/08/13 12:21:51 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

// function that opens and reads the file "numbers.dict" and then data
void	*open_file(void)
{
	int	file_description;
	int	file_description2;
	char	*file_text;

	file_description = open("numbers.dict", O_RDONLY);
	file_text = malloc(10000 * sizeof(char));
	file_description2 = read(file_description, file_text, 10000);
	close(file_description);
	close(file_description2);
	return (file_text);
}

// function that converts string into number (like atoi)
int	function_atoi(char *number)
{
	int	i;
	int	res;

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
	return (res);
}

// function that returns a number in words
char	*number_in_full(int int_number, char *char_number)
{
	char	*file_text;
	char	*result;

	file_text = open_file();
	result = "number in full";
	return (result);
}

int	main(int argc, char *argv[])
{
	int	number;
	char	*file_text;
	char	*result;

	file_text = open_file();
	if (argv[1])
		number = function_atoi(argv[1]);
	if (number < 1)
	{
		write(1, "Error\n", 6);
	}
	else if (argc == 2)
	{
		write(1, "argc == 2\n", 10);
		result = number_in_full(number, argv[1]);
	}
	else if (argc == 3)
	{
		write(1, "argc == 2\n", 10);
	}
	else if (argc == 3)
	{
		write(1, "argc == 3\n", 10);
	}
}
