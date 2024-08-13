#ifndef HUMANB_H_INCLUDED
#define HUMANB_H_INCLUDED

#include "../includes/header.h"

class HumanB {
	public:
		HumanB(std::string name);
		~HumanB(void);
		void setWeapon(Weapon &weapon);
		void attack(void);

	private:
		std::string name;
		Weapon *weapon = NULL;

};

#endif