/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:48:39 by takwak            #+#    #+#             */
/*   Updated: 2025/05/06 22:29:45 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Character::Character() {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

Character::Character(const Character& other) {
	this->_name = other._name;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other) {
	if (this == &other)
		return *this;
	this->_name = other._name;
	for (int i = 0; i < 4; i++) {
		delete this->_inventory[i];
		if (this->_inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	return *this;
}

Character::Character(const std::string &name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}


std::string const & Character::getName() const {
	return this->_name;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!this->_inventory[i]) {
			this->_inventory[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > 4 || !this->_inventory[idx])
		return ;
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 4 || !this->_inventory[idx])
		return ;
	this->_inventory[idx]->use(target);
}
