/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:34:35 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:34:36 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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



int	main( void )
{
	int size = 5;
	Animal	*arrayAnimals[2 * size];

	for (int i = 0; i < size; i++)
	{
		arrayAnimals[i] = new Dog();
		arrayAnimals[size + i] = new Cat();
	}

	std::cout << std::endl;

	for (int i = 0; i < 2 * size; i++)
		delete arrayAnimals[i];
}



// int main(void) {
// 	const Animal *dog1 = new Dog();
// 	Animal dog2 = *dog1;

// 	std::cout << dog1->getType() << ": ";
// 	dog1->makeSound();

// 	std::cout << dog2.getType() << ": ";
// 	dog2.makeSound();

// 	delete dog1;

// 	return (0);
// }