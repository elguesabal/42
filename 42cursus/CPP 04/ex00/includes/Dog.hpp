#ifndef DOG_HPP
#define DOG_HPP

#include "header.h"

class Dog: public Animal {
	public:
		Dog(void);
		Dog(const Dog &dog);
		Dog &operator = (const Dog &dog);
		~Dog(void);
		void makeSound(void) const;

};

#endif