#include "../includes/header.h"

Zombie::Zombie(void) {

}

Zombie::~Zombie(void) {
	std::cout << "Deleted: " << _name << std::endl;
}

void Zombie::setName(std::string name) {
	_name = name;
}