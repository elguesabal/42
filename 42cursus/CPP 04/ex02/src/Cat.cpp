#include "header.h"

Cat::Cat(void) : Animal() {
	std::cout << "Construtor Cat: \"Cat(void);\"" << std::endl;
	this->Animal::_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &cat) : Animal(cat) {
	std::cout << "Construtor Cat: \"Cat(const Cat &cat)\"" << std::endl;
	this->Animal::_type = cat._type;
	this->_brain = new Brain(*cat._brain);
}

Cat &Cat::operator = (const Cat &cat) {
	std::cout << "Construtor Cat: \"Cat &operator = (const Cat &cat);\"" << std::endl;
	this->Animal::_type = cat._type;
	this->_brain = new Brain(*cat._brain);
	return (*this);
}

Cat::~Cat(void) {
	std::cout << "Destrutor Cat: \"~Cat(void);\"" << std::endl;
	delete this->_brain;
}

void Cat::makeSound(void) const {
	std::cout << "Miau" << std::endl;
}