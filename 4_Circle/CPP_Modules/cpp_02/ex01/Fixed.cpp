/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 23:11:13 by takwak            #+#    #+#             */
/*   Updated: 2025/04/19 00:55:24 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_fractionalBit = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_value = other.getRawBits();
	}
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Fixed& val) {
	os << val.toFloat();
	return os;
}

Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = i << _fractionalBit;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
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
