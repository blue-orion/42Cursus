/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 23:07:38 by takwak            #+#    #+#             */
/*   Updated: 2025/04/19 22:49:36 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
private:
	int					_value;
	static const int	_fractionalBit;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& other);
	Fixed&	operator=(const Fixed& other);

	bool	operator>(const Fixed& rv) const;
	bool	operator<(const Fixed& rv) const;
	bool	operator>=(const Fixed& rv) const;
	bool	operator<=(const Fixed& rv) const;
	bool	operator==(const Fixed& rv) const;

	Fixed	operator+(const Fixed& rv) const;
	Fixed	operator-(const Fixed& rv) const;
	Fixed	operator*(const Fixed& rv) const;
	Fixed	operator/(const Fixed& rv) const;

	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);
	
	Fixed(const int i);
	Fixed(const float f);
	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(const int raw);

	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream &os, const Fixed& val);
