#include "../includes/header.h"

int main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}




	// // Weapon *club = new Weapon("crude spiked club");
	// // club->setType("arma do bob");
	// // std::cout << club->getType() << std::endl;
	// // delete club;

	// Weapon club = Weapon("crude spiked club");
	// club.setType("arma do bob");
	// std::cout << club.getType() << std::endl;


	// std::cout << std::endl;


	// // HumanA *bob = new HumanA("arma do bob", club);
	// // bob->attack();
	// // delete bob;

	// // HumanA bob = HumanA("arma do bob", club);
	// // bob.attack();

	// HumanA bob("Bob", club);
	// bob.attack();

	// Weapon arma2 = Weapon("arma do jim");
	// HumanB jim("jim");
	// // jim.setWeapon(arma2);
	// jim.attack();


	return 0;
}
