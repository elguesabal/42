#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "header.h"

class ScavTrap:public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(std::string name); // NAO TO ENTENDO ESSE ERRO
// ./src/ScavTrap.cpp:9:21: error: expected ‘)’ before ‘name’
//     9 | ScavTrap(std::string name) {
//       |         ~           ^~~~~
//       |                     )
// make: *** [Makefile:13: ScavTrap] Erro 1

	private:


};

#endif