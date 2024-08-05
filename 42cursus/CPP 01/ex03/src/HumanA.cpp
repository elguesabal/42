#include "../includes/header.h"

HumanA::HumanA(std::string name, Weapon &weapon) {
	this->name = name;
	this->weapon = weapon;
}

HumanA::~HumanA(void) {
	weapon->~Weapon();
}

void HumanA::attack(void) {
	std::cout << name << "  attacks with their " << weapon->getType() << std::endl;
}
