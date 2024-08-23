#include "ClapTrap.hpp"

int main(void) {
	ClapTrap clap1 = ClapTrap("ClapTrap");
	ClapTrap clap2 = clap1;

	std::cout << "clap1: " << clap1.teste() << std::endl;
	std::cout << "clap2: " << clap2.teste() << std::endl;

	return (0);
}