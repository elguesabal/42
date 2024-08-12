// #include "../includes/header.h"
// #include "../includes/Weapon.hpp"

HumanA::HumanA(std::string name, Weapon *weapon) {
	this->name = name;
	this->weapon = weapon;
}

// HumanA::~HumanA(void) {
// 	weapon->~Weapon();
// 	std::cout << "arma e humano deletado" << std::endl;
// }

// void HumanA::attack(void) {
// 	std::cout << name << "  attacks with their " << weapon->getType() << std::endl;
// }
