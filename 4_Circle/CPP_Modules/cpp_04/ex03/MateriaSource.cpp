/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:30:59 by takwak            #+#    #+#             */
/*   Updated: 2025/05/06 22:37:51 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
		if (other._inventory[i]) {
			_inventory[i] = other._inventory[i]->clone();
		}
		else {
			_inventory[i] = NULL;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this == &other)
		return *this;

	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
		if (other._inventory[i]) {
			_inventory[i] = other._inventory[i]->clone();
		}
		else {
			_inventory[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
	}
}

void	MateriaSource::learnMateria(AMateria *materia) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = materia;
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] && type == _inventory[i]->getType())
			return (_inventory[i]->clone());
	}
	return (NULL);
}
