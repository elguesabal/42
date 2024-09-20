#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "header.h"

class Brain {
	public:
		Brain(void);
		Brain(const Brain &brain);
		Brain &operator = (const Brain &brain);
		~Brain(void);

	protected:
		std::string ideas[100];

};

#endif