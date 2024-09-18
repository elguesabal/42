#include "header.h"

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();

// 	// ...

// 	return 0;
// }



// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	delete j; //should not create a leak
// 	delete i;

// 	// ...

// 	return 0;
// }



int main(void) {
	const Animal *dog1 = new Dog();
	Animal dog2 = *dog1;

	std::cout << dog1->getType() << ": ";
	dog1->makeSound();
	std::cout << std::endl;

	std::cout << dog2.getType() << ": ";
	dog2.makeSound();
	std::cout << std::endl;

	delete dog1;

	return (0);
}