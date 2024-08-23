#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name(""), _life(10), _energy(10), _damage(0) {

}

ClapTrap::ClapTrap(std::string name) : _name(name), _life(10), _energy(10), _damage(0) {

}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) : _name(clapTrap._name), _life(10), _energy(10), _damage(0) {

}

ClapTrap &ClapTrap::operator = (const ClapTrap &clapTrap) {
	this->_name = clapTrap._name;
	return (*this);
}

ClapTrap::~ClapTrap(void) {

}

void ClapTrap::attack(const std::string &target) {
	if (this->_life == 0) {
		std::cout << "Nao pode atacar pq esta morto!" << std::endl;
		return ;
	}

	// TERMINAR AKI

}











std::string ClapTrap::teste(void) {
	(void)_life;
	(void)_energy;
	(void)_damage;
	return (this->_name);
}