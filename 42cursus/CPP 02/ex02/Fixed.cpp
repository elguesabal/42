/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:28:44 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:28:45 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _n1(0) {

}

Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
}

Fixed::Fixed(const int fixed) {
	this->_n1 = fixed << _n2;
}

Fixed::Fixed(const float fixed) {
	this->_n1 = (int)(roundf(fixed * (1 << _n2)));
}

Fixed::~Fixed(void) {

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
	(this->_n1)++;
	return (*this);
}

Fixed &Fixed::operator -- (void) {
	(this->_n1)--;
	return (*this);
}

Fixed Fixed::operator ++ (int) {
	Fixed copy = *this;
	++(*this);
	return (copy);
}

Fixed Fixed::operator -- (int) {
	Fixed copy = *this;
	--(*this);
	return (copy);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
	return ((f1 < f2) ? f1 : f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
	return ((f1 > f2) ? f1 : f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
	return ((f1 < f2) ? f1 : f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
	return ((f1 > f2) ? f1 : f2);
}

std::ostream &operator << (std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}