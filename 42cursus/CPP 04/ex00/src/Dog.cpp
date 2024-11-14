/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:33:33 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:33:34 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

Dog::Dog(void) : Animal() {
	std::cout << "Construtor Dog: \"Dog(void);\"" << std::endl;
	this->Animal::_type = "Dog";
}

Dog::Dog(const Dog &dog) : Animal(dog) {
	std::cout << "Construtor Dog: \"Dog(const Dog &dog)\"" << std::endl;
	this->Dog::_type = dog._type;
}

Dog &Dog::operator = (const Dog &dog) {
	std::cout << "Construtor Dog: \"Dog &operator = (const Dog &dog);\"" << std::endl;
	this->Dog::_type = dog._type;
	return (*this);
}

Dog::~Dog(void) {
	std::cout << "Destrutor Dog: \"~Dog(void);\"" << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "Au au" << std::endl;
}