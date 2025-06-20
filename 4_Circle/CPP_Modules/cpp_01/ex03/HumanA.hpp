/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:47:13 by takwak            #+#    #+#             */
/*   Updated: 2025/04/21 21:30:42 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class	HumanA {
private:
	std::string	_name;
	const Weapon	&_weapon;

public:
	HumanA( const std::string &name, const Weapon &weapon);
	void	attack( void );
};
