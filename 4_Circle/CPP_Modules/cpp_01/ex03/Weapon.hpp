/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:43:49 by takwak            #+#    #+#             */
/*   Updated: 2025/04/18 16:17:40 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	Weapon {
private:
	std::string	type;

public:
	Weapon();
	Weapon( const std::string &type);
	std::string	getType( void ) const;
	void		setType( const std::string &type );
};
