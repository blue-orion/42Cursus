/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 23:56:14 by takwak            #+#    #+#             */
/*   Updated: 2025/04/20 01:13:35 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point {
private:
	const Fixed	x;
	const Fixed	y;
public:
	Point();
	Point(const float a, const float b);
	~Point();
	Point(const Point& other);
	Point&	operator=(const Point& other);

	const Fixed	getX() const;
	const Fixed	getY() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
