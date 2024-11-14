/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:25:36 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:25:37 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void) {
	Harl log;

	log.complain("debug");
	std::cout << std::endl;
	log.complain("info");
	std::cout << std::endl;
	log.complain("warning");
	std::cout << std::endl;
	log.complain("error");
	std::cout << std::endl;

	return (0);
}
