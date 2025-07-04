/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:04:09 by takwak            #+#    #+#             */
/*   Updated: 2025/05/05 17:45:35 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() {}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
	std::cout << name << " FragTrap constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) {
	this->name = other.getName();
	this->hitPoint = other.getHitPoint();
	this->energyPoint = other.getEnergyPoint();
	this->attackDamage = other.getAttackDamage();
	std::cout << name << " FragTrap constructed by copy " << other.getName() << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &other) {
	this->name = other.getName();
	this->hitPoint = other.getHitPoint();
	this->energyPoint = other.getEnergyPoint();
	this->attackDamage = other.getAttackDamage();

	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << name << " FragTrap destructed" << std::endl;
}

void	FragTrap::highFivesGuys() {
	std::cout << name << ": Let's high-fives~!" << std::endl;
}
