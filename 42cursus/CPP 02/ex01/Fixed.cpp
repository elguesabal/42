/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:26:53 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:27:20 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _n1(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int fixed) {
	std::cout << "Int constructor called" << std::endl;
	this->_n1 = fixed << _n2;
}

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