#include "ClapTrap.hpp"

int main(void) {
	ClapTrap clap("vampeta");

	clap.attack("CPP");
	clap.takeDamage(5);
	clap.beRepaired(20);

	// clap.status();

	return (0);
}