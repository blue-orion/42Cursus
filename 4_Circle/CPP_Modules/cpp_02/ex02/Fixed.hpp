/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 23:07:38 by takwak            #+#    #+#             */
/*   Updated: 2025/04/19 01:00:14 by takwak           ###   ########.fr       */
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
	Fixed& operator=(const Fixed& other);
	bool	operator>(const Fixed& rv);
	bool	operator<(const Fixed& rv);
	bool	operator>=(const Fixed& rv);
	bool	operator<=(const Fixed& rv);
	bool	operator==(const Fixed& rv);
	bool	operator!=(const Fixed& rv);
	
	Fixed(const int i);
	Fixed(const float f);
	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(const int raw);
};

std::ostream& operator<<(std::ostream &os, const Fixed& val);
