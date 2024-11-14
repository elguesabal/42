/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:41:08 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:41:09 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.h"
#include <iostream>

template <typename T> void swap(T &a, T &b) {
	T c = a;
	a = b;
	b = c;
}

template <typename T> const T min(const T &a, const T &b) {
	return( a < b ? a : b);
}

template <typename T> const T max(const T &a, const T &b) {
	return( a > b ? a : b);
}

int main( void ) {
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}

// int main(void) {
// 	int *a = new int(10);
// 	int *b = new int(20);

// 	std::cout << "a: " << *a << " b: " << *b << std::endl;
// 	swap(a, b);
// 	std::cout << "a: " << *a << " b: " << *b << std::endl;

// 	delete a;
// 	delete b;

// 	return (0);
// }