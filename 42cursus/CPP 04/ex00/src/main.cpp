#include "header.h"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	// ...

	return 0;
}



// int main(void) {
// 	Animal *animal = new Animal();
// 	std::cout << "Type " << animal->getType() << ": ";
// 	animal->makeSound();
// 	std::cout << std::endl;

// 	Animal *dog = new Dog();
// 	std::cout << "Type " << dog->getType() << ": ";
// 	dog->makeSound();
// 	std::cout << std::endl;

// 	Animal *cat = new Cat();
// 	std::cout << "Type " << cat->getType() << ": ";
// 	cat->makeSound();
// 	std::cout << std::endl;

// 	return (0);
// }