#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "header.h"

class ScavTrap:public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &scavTrap);
		ScavTrap &operator = (const ScavTrap &scavTrap);
		~ScavTrap(void);
		void attack(const std::string &target);
		void guardGate(void);

	private:


};

#endif