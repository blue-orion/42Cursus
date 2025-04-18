/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:45:29 by takwak            #+#    #+#             */
/*   Updated: 2025/04/18 16:17:53 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {};

Weapon::Weapon( const std::string &type) {
	this->type = type;
}

void	Weapon::setType( const std::string &type ) {
	this->type = type;
}

std::string	Weapon::getType( void ) const {
	return (this->type);
}
