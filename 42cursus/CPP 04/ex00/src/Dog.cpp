#include "header.h"

Dog::Dog(void) {
	std::cout << "Construtor Dog: \"Dog(void);\"" << std::endl;
	this->Animal::_type = "Dog";
}

Dog::Dog(const Dog &dog) {
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