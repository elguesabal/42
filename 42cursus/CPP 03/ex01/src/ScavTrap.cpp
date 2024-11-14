/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:30:52 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:30:53 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "Scavtrap: Chamou o construtor \"ScavTrap(void);\" sem iniciar o nome" << std::endl;
	this->_life = 100;
	this->_energy = 50;
	this->_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "Scavtrap " << name << ": Chamou o construtor \"ScavTrap(std::string name);\"" << std::endl;
	this->_life = 100;
	this->_energy = 50;
	this->_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) {
	std::cout << "Scavtrap " << scavTrap._name << ": Chamou o construtor \"ScavTrap(const ScavTrap &scavTrap);\"" << std::endl;
	this->_name = scavTrap._name;
	this->_life = scavTrap._life;
	this->_energy = scavTrap._energy;
	this->_damage = scavTrap._damage;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &scavTrap) {
	std::cout << "Scavtrap " << scavTrap._name << ": Chamou o construtor \"ScavTrap &operator = (const ScavTrap &scavTrap);\"" << std::endl;
	this->_name = scavTrap._name;
	this->_life = scavTrap._life;
	this->_energy = scavTrap._energy;
	this->_damage = scavTrap._damage;
	return (*this);
}

ScavTrap::~ScavTrap(void) {
	std::cout << "Scavtrap " << this->_name << ": Chamou o destrutor \"~ScavTrap(void);\"" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (this->_name.empty()) {
		std::cout << "\033[31m" << "Scavtrap" << "\033[0m" << ": Variavel nao inicializada (variavel _name nao inicializada)" << std::endl;
	} else if (target.empty()) {
		std::cout << "\033[31m" << "Scavtrap " << this->_name << "\033[0m" << ": Nome nao passado no argumento!" << std::endl;
	} else if (this->_life == 0) {
		std::cout << "\033[31m" << "Scavtrap " << this->_name << "\033[0m" << ": Nao pode atacar pq esta morto!" << std::endl;
	} else if (this->_energy == 0) {
		std::cout << "\033[31m" << "Scavtrap " << this->_name << "\033[0m" << ": Sem energia para atacar!" << std::endl;
	} else {
		std::cout << "Scavtrap " << this->_name << ": Infligiu " << this->_damage << " pontos em " << target << std::endl;
		--this->_energy;
	}
}

void ScavTrap::guardGate(void) {
	std::cout << "Scavtrap " << this->_name << ": Entrou no modo guarda" << std::endl;
}