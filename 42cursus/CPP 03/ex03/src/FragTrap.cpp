/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:32:33 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:32:34 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << "Fragtrap: Chamou o construtor \"FragTrap(void);\" sem iniciar o nome" << std::endl;
	this->_life = 100;
	this->_energy = 100;
	this->_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "Fragtrap " << name << ": Chamou o construtor \"FragTrap(std::string name);\"" << std::endl;
	this->_life = 100;
	this->_energy = 50;
	this->_damage = 20;
}

FragTrap::FragTrap(const FragTrap &fragTrap) {
	std::cout << "Fragtrap " << fragTrap._name << ": Chamou o construtor \"FragTrap(const FragTrap &fragTrap);\"" << std::endl;
	this->_name = fragTrap._name;
	this->_life = fragTrap._life;
	this->_energy = fragTrap._energy;
	this->_damage = fragTrap._damage;
}

FragTrap &FragTrap::operator = (const FragTrap &fragTrap) {
	std::cout << "Fragtrap " << fragTrap._name << ": Chamou o construtor \"FragTrap &operator = (const FragTrap &fragTrap);\"" << std::endl;
	this->_name = fragTrap._name;
	this->_life = fragTrap._life;
	this->_energy = fragTrap._energy;
	this->_damage = fragTrap._damage;
	return (*this);
}

FragTrap::~FragTrap(void) {
	std::cout << "Fragtrap " << this->_name << ": Chamou o destrutor \"~FragTrap(void);\"" << std::endl;
}

void FragTrap::attack(const std::string &target) {
	if (this->_name.empty()) {
		std::cout << "\033[31m" << "Fragtrap" << "\033[0m" << ": Variavel nao inicializada (variavel _name nao inicializada)" << std::endl;
	} else if (target.empty()) {
		std::cout << "\033[31m" << "Fragtrap " << this->_name << "\033[0m" << ": Nome nao passado no argumento!" << std::endl;
	} else if (this->_life == 0) {
		std::cout << "\033[31m" << "Fragtrap " << this->_name << "\033[0m" << ": Nao pode atacar pq esta morto!" << std::endl;
	} else if (this->_energy == 0) {
		std::cout << "\033[31m" << "Fragtrap " << this->_name << "\033[0m" << ": Sem energia para atacar!" << std::endl;
	} else {
		std::cout << "Fragtrap " << this->_name << ": Infligiu " << this->_damage << " pontos em " << target << std::endl;
		--this->_energy;
	}
}

void FragTrap::highFivesGuys(void) {
    std::cout << "Fragtrap " << this->_name << ": High Fives!" << std::endl;
}