/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:29:44 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:29:50 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name(""), _life(10), _energy(10), _damage(0) {
	std::cout << "Claptrap: Chamou o construtor \"ClapTrap(void)\" sem iniciar o nome" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _life(10), _energy(10), _damage(0) {
	std::cout << "Claptrap " << name << ": Chamou o construtor \"ClapTrap(std::string name)\"" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) : _name(clapTrap._name), _life(clapTrap._life), _energy(clapTrap._energy), _damage(clapTrap._damage) {
	std::cout << "Claptrap " << clapTrap._name << ": Chamou o construtor \"ClapTrap(const ClapTrap &clapTrap)\"" << std::endl;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &clapTrap) {
	std::cout << "Claptrap " << clapTrap._name << ": Chamou o construtor \"ClapTrap &operator = (const ClapTrap &clapTrap)\"" << std::endl;
	this->_name = clapTrap._name;
	this->_life = clapTrap._life;
	this->_energy = clapTrap._energy;
	this->_damage = clapTrap._damage;
	return (*this);
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Claptrap " << _name << ": Chamou o destrutor \"~ClapTrap(void)\"" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (this->_name.empty()) {
		std::cout << "\033[31m" << "Claptrap" << "\033[0m" << ": Variavel nao inicializada (variavel _name nao inicializada)" << std::endl;
	} else if (target.empty()) {
		std::cout << "\033[31m" << "Claptrap " << this->_name << "\033[0m" << ": Nome nao passado no argumento!" << std::endl;
	} else if (this->_life == 0) {
		std::cout << "\033[31m" << "Claptrap " << this->_name << "\033[0m" << ": Nao pode atacar pq esta morto!" << std::endl;
	} else if (this->_energy == 0) {
		std::cout << "\033[31m" << "Claptrap " << this->_name << "\033[0m" << ": Sem energia para atacar!" << std::endl;
	} else {
		std::cout << "Claptrap " << this->_name << ": Infligiu " << this->_damage << " pontos em " << target << std::endl;
		--this->_energy;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_name.empty()) {
		std::cout << "\033[31m" << "Claptrap" << "\033[0m" << ": Variavel nao inicializada (variavel _name nao inicializada)" << std::endl;
	} else if (this->_life == 0) {
		std::cout << "\033[31m" << "Claptrap " << this->_name << "\033[0m" << ": Nao pode tomar dano pq esta morto!" << std::endl;
	} else if ((int)(this->_life - amount) < 1) {
		std::cout << "Claptrap " << this->_name << ": Sofreu " << amount << " pontos de dano e morreu" << std::endl;
		this->_life = 0;
	} else {
		std::cout << "Claptrap " << this->_name << ": Sofreu " << amount << " pontos de dano" << std::endl;
		this->_life -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_name.empty()) {
		std::cout << "\033[31m" << "Claptrap" << "\033[0m" << ": Variavel nao inicializada (variavel _name nao inicializada)" << std::endl;
	} else if (this->_life == 0) {
		std::cout << "\033[31m" << "Claptrap " << this->_name << "\033[0m" << ": Nao pode ser reparado pq esta morto!" << std::endl;
	} else if (this->_energy == 0) {
		std::cout << "\033[31m" << "Claptrap " << this->_name << "\033[0m" << ": Sem energia para ser reparado!" << std::endl;
	} else {
		amount = ((this->_life + amount) > 10) ? 10 - this->_life : amount;
		std::cout << "Claptrap " << this->_name << ": Foi reparado em " << amount << " pontos" << std::endl;
		this->_life += amount;
		--this->_energy;
	}
}

// void ClapTrap::status(void) {
// 	std::cout << std::endl << "\t----------------------" << std::endl << std::endl;
// 	std::cout << "\tnome: " << this->_name << std::endl;
// 	std::cout << "\tvida: " << this->_life << std::endl;
// 	std::cout << "\tenergia: " << this->_energy << std::endl;
// 	std::cout << "\tdano: " << this->_damage << std::endl;
// 	std::cout << std::endl << "\t----------------------" << std::endl << std::endl;
// }