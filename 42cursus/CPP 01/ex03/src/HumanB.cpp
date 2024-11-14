/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:24:43 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:24:44 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

HumanB::HumanB(std::string name) {
	this->name = name;
}

HumanB::~HumanB(void) {

}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void HumanB::attack(void) {
	(weapon == NULL) ? std::cout << name << " has no weapon" << std::endl : std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}