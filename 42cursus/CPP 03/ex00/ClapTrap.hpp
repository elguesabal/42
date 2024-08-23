#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &clapTrap);
		ClapTrap &operator = (const ClapTrap &clapTrap);
		~ClapTrap(void);
		void attack(const std::string &target);
		// void takeDamage(unsigned int amount);
		// void beRepaired(unsigned int amount);

		std::string teste(void);

	private:
		std::string _name;
		int _life;
		int _energy;
		int _damage;


};

#endif