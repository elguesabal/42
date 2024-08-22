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



Fixed Fixed::operator + (const Fixed &fixed) const {
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator - (const Fixed &fixed) const {
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator * (const Fixed &fixed) const {
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator / (const Fixed &fixed) const {
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed &Fixed::operator = (const Fixed &fixed) {
	this->_n1 = fixed.getRawBits();
	return (*this);
}

bool Fixed::operator > (const Fixed &fixed) const {
	return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator < (const Fixed &fixed) const {
	return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator >= (const Fixed &fixed) const {
	return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator <= (const Fixed &fixed) const {
	return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator == (const Fixed &fixed) const {
	return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator != (const Fixed &fixed) const {
	return (this->toFloat() != fixed.toFloat());
}

Fixed &Fixed::operator ++ (void) {
	// (this->_n1)++;
	// return (*this);

	// std::cout << "teste: " << this->_n1 << std::endl;

	// this->_n1 = this->_n1 + 1;
	// this->_n1 = (this->_n1 + 1) << _n2;
	this->_n1 = ((int)roundf(this->toFloat() + 1)) << _n2;
	return (*this);
}

Fixed &Fixed::operator -- (void) {
	this->_n1 = ((int)roundf(this->toFloat() - 1)) << _n2;
	return (*this);
}

Fixed Fixed::operator ++ (int) {
	Fixed copy = *this;
	this->_n1 = ((int)roundf(this->toFloat() + 1)) << _n2;
	return (copy);
}

Fixed Fixed::operator -- (int) {
	Fixed copy = *this;
	this->_n1 = ((int)roundf(this->toFloat() - 1)) << _n2;
	return (copy);
}




std::ostream &operator << (std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}