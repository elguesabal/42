/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:32:39 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:32:40 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(void) {
	// ClapTrap clap("vampeta");

	// clap.attack("CPP");
	// clap.takeDamage(5);
	// clap.beRepaired(20);

	// clap.status();



	// ScavTrap scav("vampeta");

	// scav.attack("CPP");
	// scav.takeDamage(5);
	// scav.beRepaired(20);
	// scav.guardGate();

	// scav.status();



	// FragTrap frag("vampeta");

	// frag.attack("CPP");
	// frag.takeDamage(5);
	// frag.beRepaired(20);
	// frag.highFivesGuys();

	// frag.status();



	DiamondTrap diamond("vampeta");

	diamond.attack("CPP");
	diamond.takeDamage(500);
	diamond.beRepaired(20);
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.whoAmI();

	// diamond.status();

	return (0);
}