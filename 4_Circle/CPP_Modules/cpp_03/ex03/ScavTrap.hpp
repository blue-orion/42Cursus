/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 23:09:19 by takwak            #+#    #+#             */
/*   Updated: 2025/05/05 16:48:03 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
	static const int _defaultHitPoint = 100;
	static const int _defaultEnergyPoint = 50;
	static const int _defaultAttackDamage = 20;

	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);
	virtual ~ScavTrap();

	ScavTrap& operator=(const ScavTrap& other);

	void	attack(const std::string& target);
	void	guardGate();
};
