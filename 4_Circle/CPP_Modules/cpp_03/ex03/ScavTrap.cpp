/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 23:16:10 by takwak            #+#    #+#             */
/*   Updated: 2025/05/05 16:51:53 by takwak           ###   ########.fr       */
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
	this->hitPoint = _defaultHitPoint;
	this->energyPoint = _defaultEnergyPoint;
	this->attackDamage = _defaultAttackDamage;
	std::cout << this->name  << " ScavTrap "<< "constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
	this->name = other.getName();
	this->hitPoint = other.getHitPoint();
	this->energyPoint = other.getEnergyPoint();
	this->attackDamage = other.getAttackDamage();
	std::cout << "ScavTrap constructed by copy " << other.getName() << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &other) {
	this->name = other.getName();
	this->hitPoint = other.getHitPoint();
	this->energyPoint = other.getEnergyPoint();
	this->attackDamage = other.getAttackDamage();

	return (*this);
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
	this->energyPoint--;
}
