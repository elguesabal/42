#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "header.h"

class Animal {
	public:
		Animal(const Animal &animal);
		Animal &operator = (const Animal &animal);
		virtual ~Animal(void);
		virtual void makeSound(void) const;
		std::string getType(void) const;

	protected:
		Animal(void);
		std::string _type;

};

#endif