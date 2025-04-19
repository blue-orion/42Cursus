/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:39:05 by takwak            #+#    #+#             */
/*   Updated: 2025/04/20 01:44:27 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	f1((a.getY() - b.getY()) * (point.getX() - a.getX())
			- (a.getX() - b.getX()) * (point.getY() - a.getY()));
	Fixed	f2((b.getY() - c.getY()) * (point.getX() - b.getX())
			- (b.getX() - c.getX()) * (point.getY() - b.getY()));
	Fixed	f3((c.getY() - a.getY()) * (point.getX() - c.getX())
			- (c.getX() - a.getX()) * (point.getY() - c.getY()));

	if (f1 > 0 && f2 > 0 && f3 > 0)
		return true;
	if (f1 < 0 && f2 < 0 && f3 < 0)
		return true;
	return false;
}
