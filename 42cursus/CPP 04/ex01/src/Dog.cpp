/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:34:30 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:34:31 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

Dog::Dog(void) : Animal() {
	std::cout << "Construtor Dog: \"Dog(void);\"" << std::endl;
	this->Animal::_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &dog) : Animal(dog) {
	std::cout << "Construtor Dog: \"Dog(const Dog &dog);\"" << std::endl;
	this->Animal::_type = dog._type;
	this->_brain = new Brain(*dog._brain);
}

Dog &Dog::operator = (const Dog &dog) {
	std::cout << "Construtor Dog: \"Dog &operator = (const Dog &dog);\"" << std::endl;
	this->Animal::_type = dog._type;
	this->_brain = new Brain(*dog._brain);
	return (*this);
}

Dog::~Dog(void) {
	std::cout << "Destrutor Dog: \"~Dog(void);\"" << std::endl;
	delete this->_brain;
}

void Dog::makeSound(void) const {
	std::cout << "Au au" << std::endl;
}