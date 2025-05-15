/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:06:04 by takwak            #+#    #+#             */
/*   Updated: 2025/05/15 18:07:26 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : a(10), b(20), c(30) {}
Data::~Data() {}
Data::Data(const Data& other) : a(other.a), b(other.b), c(other.c) {}

Data&	Data::operator=(const Data& other) {
	if (this == &other)
		return *this;
	this->a = other.a;
	this->b = other.b;
	this->c = other.c;
	return *this;
}
