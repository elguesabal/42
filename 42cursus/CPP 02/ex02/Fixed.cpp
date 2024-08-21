#include "Fixed.hpp"

Fixed::Fixed(void) : _n1(0) {
	// this->_n1 = 0; // OU : _n1(0) TANTO FAZ (EU ACHO)
}

Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
}

// Fixed::Fixed(const int fixed) : _n1(fixed << _n2) {
Fixed::Fixed(const int fixed) {
	this->_n1 = fixed << _n2;
}

// Fixed::Fixed(const float fixed) : _n1((int)roundf(fixed * (1 << _n2))) {
Fixed::Fixed(const float fixed) {
	this->_n1 = (int)(roundf(fixed * (1 << _n2)));
}

Fixed &Fixed::operator = (const Fixed &fixed) {
	this->_n1 = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed(void) {
	// std::cout << "Default called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return (this->_n1);
}

void Fixed::setRawBits(const int raw) {
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

Fixed Fixed::operator + (const Fixed &fixed) const {
	return (Fixed(this->toInt() + fixed.toInt()));
}