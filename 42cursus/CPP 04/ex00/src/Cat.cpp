/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:33:31 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:33:32 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

Cat::Cat(void) : Animal() {
	std::cout << "Construtor Cat: \"Cat(void);\"" << std::endl;
	this->Animal::_type = "Cat";
}

Cat::Cat(const Cat &cat) : Animal(cat) {
	std::cout << "Construtor Cat: \"Cat(const Cat &cat)\"" << std::endl;
	this->Animal::_type = cat._type;
}

Cat &Cat::operator = (const Cat &cat) {
	std::cout << "Construtor Cat: \"Cat &operator = (const Cat &cat);\"" << std::endl;
	this->Animal::_type = cat._type;
	return (*this);
}

Cat::~Cat(void) {
	std::cout << "Destrutor Cat: \"~Cat(void);\"" << std::endl;
}

void Cat::makeSound(void) const {
	std::cout << "Miau" << std::endl;
}