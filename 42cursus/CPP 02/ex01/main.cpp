/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:27:28 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:27:29 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int main( void ) {
// 	Fixed a;
// 	Fixed b( a );
// 	Fixed c;

// 	c = b;

// 	std::cout << a.getRawBits() << std::endl;
// 	std::cout << b.getRawBits() << std::endl;
// 	std::cout << c.getRawBits() << std::endl;

// 	return 0;
// }



int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}



// int main(void) {
// 	// Fixed a;
// 	// a.setRawBits(10);
// 	// std::cout << a.getRawBits() << std::endl;

// 	// Fixed const b(10);
// 	// // std::cout << b.getRawBits() << std::endl;
// 	// std::cout << b.toInt() << std::endl;
// 	// std::cout << b.toFloat() << std::endl;

// 	// std::cout << std::endl;

// 	// Fixed const c(5.50f);
// 	// std::cout << c.toInt() << std::endl;
// 	// std::cout << c.toFloat() << std::endl;

// 	// std::cout << std::endl;

// 	// Fixed const d(10.10f);
// 	// std::cout << d << std::endl;

// 	return (0);
// }