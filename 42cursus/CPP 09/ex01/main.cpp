/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:43:02 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:43:03 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error" << std::endl;
		return (0);
	}
	try {
		RPN rpn(argv[1]);

		rpn.readArg();
		std::cout << rpn.result() << std::endl;
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	return (0);
}