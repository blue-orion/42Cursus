/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:09:33 by takwak            #+#    #+#             */
/*   Updated: 2025/05/05 16:47:55 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	static const int _defaultHitPoint = 100;
	static const int _defaultEnergyPoint = 100;
	static const int _defaultAttackDamage = 30;

	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& other);
	virtual ~FragTrap();

	FragTrap& operator=(const FragTrap& other);

	void	highFivesGuys();
};
