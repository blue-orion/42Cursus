/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:29:40 by takwak            #+#    #+#             */
/*   Updated: 2025/05/05 16:54:03 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() {}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"),  ScavTrap(name), FragTrap(name) {
	this->name = name;
	this->hitPoint = FragTrap::_defaultHitPoint;
	this->energyPoint = ScavTrap::_defaultEnergyPoint;
	this->attackDamage = FragTrap::_defaultAttackDamage;
}

DiamondTrap::~DiamondTrap() {
	std::cout << name << " DiamondTrap destroyed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {
	this->name = other.name;
	this->hitPoint = other.hitPoint;
	this->energyPoint = other.energyPoint;
	this->attackDamage = other.attackDamage;
}

void	DiamondTrap::whoAmI() {
	std::cout << "I am " << name << " in DiamondTrap" << std::endl;
	std::cout << "My parent's name is " << this->getName() << std::endl;
}
