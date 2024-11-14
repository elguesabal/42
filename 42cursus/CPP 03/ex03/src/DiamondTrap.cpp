/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:32:24 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:32:25 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap: Chamou o construtor \"DiamondTrap(void);\" sem iniciar o nome" << std::endl;
	this->_name = "";
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_life = this->FragTrap::_life;
	this->_energy = this->ScavTrap::_energy;
	this->_damage = this->FragTrap::_damage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	std::cout << "DiamondTrap " << name << ": Chamou o construtor \"DiamondTrap(std::string name);\"" << std::endl;
	this->_name = name;
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_life = this->FragTrap::_life;
	this->_energy = this->ScavTrap::_energy;
	this->_damage = this->FragTrap::_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) : ClapTrap(diamondTrap), ScavTrap(diamondTrap), FragTrap(diamondTrap) {
	std::cout << "DiamondTrap " << diamondTrap._name << ": Chamou o construtor \"DiamondTrap(const DiamondTrap &diamondTrap);\"" << std::endl;
	this->_name = diamondTrap._name;
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_life = diamondTrap._life;
	this->_energy = diamondTrap._energy;
	this->_damage = diamondTrap._damage;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &diamondTrap) {
	std::cout << "DiamondTrap " << diamondTrap._name << ": Chamou o construtor \"DiamondTrap &operator = (const DiamondTrap &diamondTrap);\"" << std::endl;
	this->_name = diamondTrap._name;
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_life = diamondTrap._life;
	this->_energy = diamondTrap._energy;
	this->_damage = diamondTrap._damage;
	return (*this);
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << this->_name << ": Chamou o destrutor \"~DiamondTrap(void);\"" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap " << this->_name << ": " << this->ClapTrap::_name << std::endl;
}