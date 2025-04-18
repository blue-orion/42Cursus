/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:59:28 by takwak            #+#    #+#             */
/*   Updated: 2025/04/18 14:37:50 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	Zombie {
private:
	std::string	name;

public:
	Zombie();
	Zombie( std::string name );
	~Zombie( void );

	void	announce( void );
	void	setName( std::string name );
};

Zombie	*zombieHorde( int N, std::string name );
