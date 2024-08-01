#include "../includes/header.h"

int main(void) {
	Zombie *zombie = newZombie("newZombie");
	zombie->announce();
	delete zombie;

	std::cout << std::endl << std::endl;

	randomChump("randomChump");

	std::cout << std::endl << std::endl;

	zombieHorde(10, "zumbieHorde"); // USAR delete
	return (0);
}