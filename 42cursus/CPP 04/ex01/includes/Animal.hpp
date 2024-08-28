#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "header.h"

class Animal {
	public:
		Animal(void);
		Animal(const Animal &animal);
		Animal &operator = (const Animal &animal);
		~Animal(void);
		virtual void makeSound(void) const;
		std::string getType(void) const;

	protected:
		std::string _type;

};

#endif