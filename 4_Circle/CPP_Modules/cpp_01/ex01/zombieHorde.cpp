/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:59:18 by takwak            #+#    #+#             */
/*   Updated: 2025/04/18 14:58:16 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>
#include <iostream>

Zombie	*zombieHorde( int N, std::string name ) {
	Zombie	*horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		std::stringstream	ss;

		ss << name << i;
		horde[i].setName(ss.str());
		horde[i].announce();
	}
	return horde;
}

