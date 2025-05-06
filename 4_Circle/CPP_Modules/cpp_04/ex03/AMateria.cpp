/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:09:04 by takwak            #+#    #+#             */
/*   Updated: 2025/05/06 17:17:29 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(std::string const &type) {
	this->type = type;
}

std::string const & AMateria::getType() const {
	return this->type;
}

void	AMateria::use(ICharacter& target) {
	if (this->type == "ice") {
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	}
	if (this->type == "cure") {
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	}
}
