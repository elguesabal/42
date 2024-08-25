#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name(""), _life(10), _energy(10), _damage(0) {
	// PREENCHER AKI COM UM AVISO
}

ClapTrap::ClapTrap(std::string name) : _name(name), _life(10), _energy(10), _damage(0) {
	// PREENCHER AKI COM UM AVISO

}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) : _name(clapTrap._name), _life(clapTrap._life), _energy(clapTrap._energy), _damage(clapTrap._damage) {
	// PREENCHER AKI COM UM AVISO

}

ClapTrap &ClapTrap::operator = (const ClapTrap &clapTrap) {
	this->_name = clapTrap._name;
	return (*this);
}

ClapTrap::~ClapTrap(void) {
	// PREENCHER AKI COM UM AVISO

}

void ClapTrap::attack(const std::string &target) {
	if (this->_name.empty()) {
		std::cout << "\033[31m" << "Variavel nao inicializada (variavel _name nao inicializada)" << "\033[0m" << std::endl;
	} else if (target.empty()) {
		std::cout << "\033[31m" << this->_name << "\033[0m" << ": Nome nao passado no argumento!" << std::endl;
	} else if (this->_life == 0) {
		std::cout << "\033[31m" << this->_name << "\033[0m" << ": Nao pode atacar pq esta morto!" << std::endl;
	} else if (this->_energy == 0) {
		std::cout << "\033[31m" << this->_name << "\033[0m" << ": Sem energia para atacar!" << std::endl;
	} else {
		std::cout << this->_name << ": Infligiu " << this->_damage << " pontos em " << target << std::endl;
		--this->_energy;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_name.empty()) {
		std::cout << "\033[31m" << "Variavel nao inicializada (variavel _name nao inicializada)" << "\033[0m" << std::endl;
	} else if (this->_life == 0) {
		std::cout << "\033[31m" << this->_name << "\033[0m" << ": Nao pode tomar dano pq esta morto!" << std::endl;
	} else if ((int)(this->_life - amount) < 1) {
		std::cout << this->_name << ": Sofreu " << amount << " pontos de dano e morreu" << std::endl;
		this->_life = 0;
	} else {
		std::cout << this->_name << ": Sofreu " << amount << " pontos de dano" << std::endl;
		this->_life -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_name.empty()) {
		std::cout << "\033[31m" << "Variavel nao inicializada (variavel _name nao inicializada)" << "\033[0m" << std::endl;
	} else if (this->_life == 0) {
		std::cout << "\033[31m" << this->_name << "\033[0m" << ": Nao pode ser reparado pq esta morto!" << std::endl;
	} else if (this->_energy == 0) {
		std::cout << "\033[31m" << this->_name << "\033[0m" << ": Sem energia para ser reparado!" << std::endl;
	} else {
		// if ((this->_life + amount) > 10)
			// amount = 10 - this->_life;
		amount = ((this->_life + amount) > 10) ? 10 - this->_life : amount;

		std::cout << this->_name << ": Foi reparado em " << amount << " pontos" << std::endl;
		this->_life += amount;
		--this->_energy;
	}
}




void ClapTrap::status(void) {
	std::cout << std::endl << "\t----------------------" << std::endl << std::endl;
	std::cout << "\tnome: " << this->_name << std::endl;
	std::cout << "\tvida: " << this->_life << std::endl;
	std::cout << "\tenergia: " << this->_energy << std::endl;
	std::cout << "\tdano: " << this->_damage << std::endl;
	std::cout << std::endl << "\t----------------------" << std::endl << std::endl;
}