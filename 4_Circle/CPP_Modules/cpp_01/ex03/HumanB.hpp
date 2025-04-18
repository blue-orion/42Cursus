/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:53:46 by takwak            #+#    #+#             */
/*   Updated: 2025/04/18 16:47:35 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class	HumanB {
private:
	const Weapon	*_weapon;
	std::string	_name;
	
public:
	HumanB( std::string name );
	void	attack( void );
	void	setWeapon( const Weapon &weapon );
};
