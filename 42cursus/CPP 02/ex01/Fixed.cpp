#include "Fixed.hpp"

Fixed::Fixed(void) : _n1(0) {
	std::cout << "Default constructor called" << std::endl;
	// this->_n1 = 0; // OU : _n1(0) TANTO FAZ (EU ACHO)
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

// Fixed::Fixed(const int fixed) : _n1(fixed << _n2) {
Fixed::Fixed(const int fixed) {
	std::cout << "Int constructor called" << std::endl;
	this->_n1 = fixed << _n2;
}

// Fixed::Fixed(const float fixed) : _n1((int)roundf(fixed * (1 << _n2))) {
Fixed::Fixed(const float fixed) {
	std::cout << "Float constructor called" << std::endl;
	this->_n1 = (int)(roundf(fixed * (1 << _n2)));
}

Fixed &Fixed::operator = (const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_n1 = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed(void) {
	std::cout << "Default called" << std::endl;
}

int Fixed::getRawBits(void) const {
	// std::cout << "getRawBIts member function called" << std::endl;
	return (this->_n1);
}

void Fixed::setRawBits(const int raw) {
	// std::cout << "setRawBIts member function called" << std::endl;
	this->_n1 = raw;
}

float Fixed::toFloat(void) const {
	return ((float)this->_n1 / (1 << this->_n2));
}

int Fixed::toInt(void) const {
	return ((int)(roundf((float)this->_n1 / (1 << this->_n2))));
}

std::ostream &operator << (std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}