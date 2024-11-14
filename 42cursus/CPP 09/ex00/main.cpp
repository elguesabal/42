/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:42:56 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:42:57 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include " BitcoinExchange.hpp"

int main(int argc, char **argv) {
	try {
		BitcoinExchange bitcoin(argc, argv[1]);
		bitcoin.readInput();
	} catch (std::exception &error) {
		std::cout << "Error: " << error.what() << std::endl;
		return (0);
	}

	return (0);
}