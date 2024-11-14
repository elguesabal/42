/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:25:50 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:25:52 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl log;

	if (argc == 2)
		log.complain(argv[1]);
	else
		std::cout << "Wrong number of arguments!" << std::endl;

	return (0);
}