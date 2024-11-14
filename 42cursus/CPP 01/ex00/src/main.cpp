/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:23:33 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:23:35 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int main(void) {
	Zombie *zombie = newZombie("newZombie");
	zombie->announce();
	delete zombie;

	std::cout << std::endl << std::endl;

	randomChump("randomChump");
	return (0);
}