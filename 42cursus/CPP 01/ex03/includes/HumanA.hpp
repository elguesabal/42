#ifndef HUMANA_H_INCLUDED
#define HUMANA_H_INCLUDED

#include "../includes/header.h"

class HumanA {
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void attack(void);

	private:
		std::string name;
		Weapon &weapon;

};


#endif