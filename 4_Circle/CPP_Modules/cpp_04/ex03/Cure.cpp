/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:22:27 by takwak            #+#    #+#             */
/*   Updated: 2025/05/06 22:29:29 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}
Cure::~Cure() {}
Cure::Cure(const Cure& other) : AMateria(other._type) {}

Cure& Cure::operator=(const Cure& other) {
	if (this == &other)
		return *this;
	this->_type = other._type;
	return *this;
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const {
	return new Cure;
}
