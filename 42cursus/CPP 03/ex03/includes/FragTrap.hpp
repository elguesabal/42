#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "header.h"

class FragTrap:public virtual ClapTrap {
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &fragTrap);
		FragTrap &operator = (const FragTrap &fragTrap);
		~FragTrap(void);
		void attack(const std::string &target);
        void highFivesGuys(void);

	private:

};

#endif