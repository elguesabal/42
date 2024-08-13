#include "../includes/header.h"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon) {
	this->name = name;
}

HumanA::~HumanA(void) {

}

void HumanA::attack(void) {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
