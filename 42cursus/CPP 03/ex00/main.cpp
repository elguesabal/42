/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:30:03 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:30:04 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	ClapTrap clap("vampeta");

	clap.attack("CPP");
	clap.takeDamage(5);
	clap.beRepaired(20);

	// clap.status();

	return (0);
}