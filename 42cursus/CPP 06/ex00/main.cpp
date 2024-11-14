/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:39:38 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:39:39 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if	(argc != 2) {
		std::cout << "Error: Número errado de argumentos" << std::endl;
		return (0);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}