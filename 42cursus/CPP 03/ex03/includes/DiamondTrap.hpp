#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "header.h"

class DiamondTrap:public ScavTrap, public FragTrap {
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &diamondTrap);
		DiamondTrap &operator = (const DiamondTrap &diamondTrap);
		~DiamondTrap(void);
		void attack(const std::string &target);
		void whoAmI(void);

	private:
		std::string _name;

};

#endif