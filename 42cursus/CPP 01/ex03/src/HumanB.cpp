#include "../includes/header.h"

HumanB::HumanB(std::string name) {
    this->name = name;
}

HumanB::~HumanB(void) {

}

void HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}

void HumanB::attack(void) {
    (weapon == NULL) ? std::cout << name << " has no weapon" << std::endl : std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}