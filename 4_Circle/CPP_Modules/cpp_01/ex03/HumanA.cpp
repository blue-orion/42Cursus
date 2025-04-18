/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:56:09 by takwak            #+#    #+#             */
/*   Updated: 2025/04/18 16:45:29 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA( const std::string &name, const Weapon &weapon) : _name(name), _weapon(weapon) {}

void	HumanA::attack( void ) {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
