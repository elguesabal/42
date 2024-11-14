/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:30:42 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:30:43 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(void) {
	// ClapTrap clap("vampeta");

	// clap.attack("CPP");
	// clap.takeDamage(5);
	// clap.beRepaired(20);

	// clap.status();



	ScavTrap scav("vampeta");

	scav.attack("CPP");
	// scav.takeDamage(5);
	// scav.beRepaired(20);
	// scav.guardGate();

	scav.status();

	return (0);
}