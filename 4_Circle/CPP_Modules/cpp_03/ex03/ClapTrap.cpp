/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 02:07:46 by takwak            #+#    #+#             */
/*   Updated: 2025/05/05 16:51:34 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() {
	std::cout << "Default ClapTrap constructed" << std::endl;
}
ClapTrap::~ClapTrap() {
	std::cout << name << " ClapTrap destroyed" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoint(10), energyPoint(10), attackDamage(0){
	std::cout << name << " ClapTrap constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << name << " ClapTrap constructed" << std::endl;
	this->name = other.getName();
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	if (this == &other)
		return *this;
	this->name = other.getName();
	return *this;
}

std::string	ClapTrap::getName() const {
	return (this->name);
}

unsigned int	ClapTrap::getAttackDamage() const {
	return this->attackDamage;
}
unsigned int	ClapTrap::getHitPoint() const {
	return this->hitPoint;
}
unsigned int	ClapTrap::getEnergyPoint() const {
	return this->energyPoint;
}

void	ClapTrap::attack(const std::string& target) {
	std::cout << "ClapTrap " << name << " attacks " << target;

	if (energyPoint == 0) {
		std::cout << ", But " << name << "'s energyPoint is " << energyPoint
			<< ", can't do anything" << std::endl;
		return ;
	}
	if (hitPoint == 0) {
		std::cout << ", But " << name << "'s hitPoint is " << hitPoint
			<< ", can't do anything" << std::endl;
		return ;
	}

	std::cout << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	unsigned int	tmp = hitPoint;

	if (hitPoint >= amount) {
		hitPoint -= amount;
	}
	else {
		hitPoint = 0;
	}
	std::cout << name << " take damage by " << amount 
		<< " (" << tmp << "->" << hitPoint << ")" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << name << " try to repair" << std::endl;
	if (energyPoint == 0) {
		std::cout << "But " << name << "'s energyPoint is " << energyPoint
			<< ", can't do anything" << std::endl;
		return ;
	}
	if (hitPoint == 0) {
		std::cout << "But " << name << "'s hitPoint is " << hitPoint
			<< ", can't do anything" << std::endl;
		return ;
	}

	hitPoint += amount;
	std::cout << name << " is repaired by " << amount
			<< " (" << hitPoint - amount << "->" << hitPoint << ")" << std::endl;
	energyPoint--;
}
