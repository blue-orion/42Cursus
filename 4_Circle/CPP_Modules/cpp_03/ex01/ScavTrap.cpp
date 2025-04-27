/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 23:16:10 by takwak            #+#    #+#             */
/*   Updated: 2025/04/28 00:03:53 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "Default ScavTrap constructed" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << this->getName() << " ScavTrap destroyed" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->setAttackDamage(20);
	this->setEnergyPoint(50);
	this->setHitPoint(100);
	std::cout << "ScavTrap " << this->getName() << " constructed" << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << this->getName() << " is now in Gate Keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	std::cout << "ScavTrap " << this->getName() << " attacks " << target;

	if (this->getEnergyPoint() == 0) {
		std::cout << ", But " << this->getName() << "'s energyPoint is " << this->getEnergyPoint()
			<< ", can't do anything" << std::endl;
		return ;
	}
	if (this->getHitPoint() == 0) {
		std::cout << ", But " << this->getName() << "'s hitPoint is " << this->getHitPoint()
			<< ", can't do anything" << std::endl;
		return ;
	}

	std::cout << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}
