/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:28:57 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:28:58 by joseanto         ###   ########.fr       */
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



// int main( void ) {
// 	Fixed a;
// 	Fixed const b( 10 );
// 	Fixed const c( 42.42f );
// 	Fixed const d( b );

// 	a = Fixed( 1234.4321f );

// 	std::cout << "a is " << a << std::endl;
// 	std::cout << "b is " << b << std::endl;
// 	std::cout << "c is " << c << std::endl;
// 	std::cout << "d is " << d << std::endl;

// 	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// 	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// 	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// 	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

// 	return 0;
// }



int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}



// int main(void) {
// 	Fixed a = Fixed(5);
// 	Fixed b(2);
// 	Fixed c = Fixed::min(a, b);

// 	// a = a + b;
// 	// a = a - b;
// 	// a = a * b;
// 	// a = a / b;

// 	std::cout << "a: " << a << std::endl;
// 	std::cout << "b: " << b << std::endl;
// 	std::cout << "c: " << c << std::endl;
// 	// std::cout << std::endl << "result: " << std::endl;

// 	// std::cout << (a + b) << std::endl;
// 	// std::cout << (a - b) << std::endl;
// 	// std::cout << (a * b) << std::endl;
// 	// std::cout << (a / b) << std::endl;

// 	// std::cout << (a > b) << std::endl;
// 	// std::cout << (a < b) << std::endl;
// 	// std::cout << (a >= b) << std::endl;
// 	// std::cout << (a <= b) << std::endl;
// 	// std::cout << (a == b) << std::endl;
// 	// std::cout << (a != b) << std::endl;

// 	// std::cout << ++a << std::endl;
// 	// std::cout << --b << std::endl;
// 	// std::cout << a++ << std::endl;
// 	// std::cout << b-- << std::endl;

// 	return (0);
// }