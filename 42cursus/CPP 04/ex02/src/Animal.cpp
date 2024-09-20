#include "header.h"

Animal::Animal(void) : _type("Animal") {
	std::cout << "Construtor Animal: \"Animal(void);\"" << std::endl;
}

Animal::Animal(const Animal &animal) : _type(animal._type) {
	std::cout << "Construtor Animal: \"Animal(const Animal &animal)\"" << std::endl;
}

Animal &Animal::operator = (const Animal &animal) {
	std::cout << "Construtor Animal: \"Animal &operator = (const Animal &animal);\"" << std::endl;
	this->_type = animal._type;
	return (*this);
}

Animal::~Animal(void) {
	std::cout << "Destrutor Animal: \"~Animal(void);\"" << std::endl;
}

void Animal::makeSound(void) const {
	std::cout << "Class Animal" << std::endl;
}

std::string Animal::getType(void) const {
	return (this->_type);
}