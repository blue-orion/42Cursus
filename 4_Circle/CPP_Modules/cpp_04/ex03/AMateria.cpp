/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:09:04 by takwak            #+#    #+#             */
/*   Updated: 2025/05/06 22:14:15 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria() {}
AMateria::AMateria(const AMateria& other) : _type(other._type) {}
AMateria::~AMateria() {}
AMateria&	AMateria::operator=(const AMateria& other) {
	if (this != &other)
		return *this;
	this->_type = other._type;
	return *this;
}

AMateria::AMateria(std::string const &type) : _type(type) {}

std::string const & AMateria::getType() const {
	return this->_type;
}

void	AMateria::use(ICharacter& target) {
	std::cout << "Default using Materia at " << target.getName() << std::endl;
}
