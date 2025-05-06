/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:27:20 by takwak            #+#    #+#             */
/*   Updated: 2025/05/06 22:29:37 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}
Ice::Ice(const Ice& other) : AMateria(other.getType()) {}
Ice::~Ice() {}

Ice& Ice::operator=(const Ice& other) {
	if (this == &other)
		return *this;
	this->_type = other._type;
	return *this;
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const {
	return new Ice;
}
