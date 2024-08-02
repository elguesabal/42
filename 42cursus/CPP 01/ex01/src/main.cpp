#include "../includes/header.h"

int main(void) {
	Zombie *zombies = zombieHorde(3, "zumbieHorde");

	delete[] zombies;
	return (0);
}