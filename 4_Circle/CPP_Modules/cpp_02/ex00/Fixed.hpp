/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 23:07:38 by takwak            #+#    #+#             */
/*   Updated: 2025/04/18 23:36:30 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed {
private:
	int					_value;
	static const int	_fractionalBit;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed&);
	Fixed& operator=(const Fixed&);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);
};
