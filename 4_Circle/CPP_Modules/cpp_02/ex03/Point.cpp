/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:00:20 by takwak            #+#    #+#             */
/*   Updated: 2025/04/20 01:01:54 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}
Point::Point(const float a, const float b) : x(a), y(b) {}
Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::~Point() {}

const Fixed	Point::getX() const {
	return this->x;
}
const Fixed	Point::getY() const {
	return this->y;
}

