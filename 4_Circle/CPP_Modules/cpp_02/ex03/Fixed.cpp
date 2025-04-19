/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 23:11:13 by takwak            #+#    #+#             */
/*   Updated: 2025/04/19 23:16:19 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_fractionalBit = 8;

Fixed::Fixed() {
	this->_value = 0;
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		this->_value = other.getRawBits();
	}
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Fixed& val) {
	os << val.toFloat();
	return os;
}

bool	Fixed::operator>(const Fixed &rv) const {
	return this->_value > rv.getRawBits();
}
bool	Fixed::operator<(const Fixed &rv) const {
	return this->_value < rv.getRawBits();
}
bool	Fixed::operator>=(const Fixed &rv) const {
	return this->_value >= rv.getRawBits();
}
bool	Fixed::operator<=(const Fixed &rv) const {
	return this->_value <= rv.getRawBits();
}
bool	Fixed::operator==(const Fixed &rv) const {
	return this->_value == rv.getRawBits();
}


Fixed	Fixed::operator+(const Fixed& rv) const {
	Fixed	tmp;

	tmp.setRawBits(this->_value + rv._value);
	return tmp;
}
Fixed	Fixed::operator-(const Fixed& rv) const {
	Fixed	tmp;

	tmp.setRawBits(this->_value - rv._value);
	return tmp;
}
Fixed	Fixed::operator*(const Fixed& rv) const {
	Fixed	tmp;

	int64_t	temp = static_cast<int64_t>(this->_value) * static_cast<int64_t>(rv._value);
	tmp.setRawBits(static_cast<int>(temp >> _fractionalBit));
	return tmp;
}
Fixed	Fixed::operator/(const Fixed& rv) const {
	Fixed	tmp;

	int64_t	temp = (static_cast<int64_t>(this->_value) << _fractionalBit) / static_cast<int64_t>(rv._value);
	tmp.setRawBits(static_cast<int>(temp));
	return tmp;
}

Fixed&	Fixed::operator++(void) {
	this->_value += 1;

	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);

	this->_value += 1;
	return (tmp);
}

Fixed&	Fixed::operator--(void) {
	this->_value -= 1;

	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);

	this->_value -= 1;
	return (tmp);
}

Fixed::Fixed(const int i) {
	this->_value = i << _fractionalBit;
}

Fixed::Fixed(const float f) {
	this->_value = roundf(f * (1 << _fractionalBit));
}

float	Fixed::toFloat(void) const {
	return (static_cast<float>(_value) / (1 << _fractionalBit));
}

int	Fixed::toInt(void) const {
	return (_value >> _fractionalBit);
}

int	Fixed::getRawBits(void) const {
	return (this->_value);
}

void	Fixed::setRawBits(const int raw) {
	this->_value = raw;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}
const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}
Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}
