#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}



// int main(void) {
// 	Fixed n1;
// 	Fixed n2(n1);
// 	Fixed n3;

// 	n3 = n1;

// 	std::cout << n1.getRawBits() << std::endl;
// 	std::cout << n2.getRawBits() << std::endl;
// 	std::cout << n3.getRawBits() << std::endl;

// 	n1.setRawBits(1);
// 	n2.setRawBits(2);
// 	n3.setRawBits(3);

// 	std::cout << n1.getRawBits() << std::endl;
// 	std::cout << n2.getRawBits() << std::endl;
// 	std::cout << n3.getRawBits() << std::endl;

// 	return (0);
// }