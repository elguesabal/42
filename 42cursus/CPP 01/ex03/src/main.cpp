#include "../includes/header.h"

int main(void)
{
	// {
	// 	Weapon club = Weapon("crude spiked club");
	// 	HumanA bob("Bob", club);
	// 	bob.attack();
	// 	club.setType("some other type of club");
	// 	bob.attack();
	// }
	// {
	// 	Weapon club = Weapon("crude spiked club");
	// 	HumanB jim("Jim");
	// 	jim.setWeapon(club);
	// 	jim.attack();
	// 	club.setType("some other type of club");
	// 	jim.attack();
	// }



	Weapon club = Weapon("crude spiked club");
	club.setType("teste");
	std::cout << club.getType() << std::endl;


	std::cout << std::endl;


	HumanA *bob = new HumanA("teste", club);
	// HumanA bob = HumanA("teste", club);
	// HumanA bob("Bob", club);
	bob->attack();
	// bob.attack();



	return 0;
}
