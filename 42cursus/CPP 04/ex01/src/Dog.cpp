#include "header.h"

Dog::Dog(void) : Animal("Dog"), _brain(new Brain()) {
	std::cout << "Construtor Dog: \"Dog(void);\"" << std::endl;
	this->Animal::_type = "Dog";
	// this->_brain = new Brain();
}

Dog::Dog(const Dog &dog) {
	std::cout << "Construtor Dog: \"Dog(const Dog &dog);\"" << std::endl;
	this->Dog::_type = dog._type;
}

Dog &Dog::operator = (const Dog &dog) {
	std::cout << "Construtor Dog: \"Dog &operator = (const Dog &dog);\"" << std::endl;
	this->Dog::_type = dog._type;
	return (*this);
}

Dog::~Dog(void) {
	std::cout << "Destrutor Dog: \"~Dog(void);\"" << std::endl;
	// delete this->_brain;
}

void Dog::makeSound(void) const {
	std::cout << "Au au" << std::endl;
}