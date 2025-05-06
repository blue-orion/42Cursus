/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:07:19 by takwak            #+#    #+#             */
/*   Updated: 2025/05/06 22:38:32 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* ice_tmp;
	ice_tmp = src->createMateria("ice");
	me->equip(ice_tmp);

	AMateria* cure_tmp;
	cure_tmp = src->createMateria("cure");
	me->equip(cure_tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(0);
	me->unequip(1);

	delete ice_tmp;
	delete cure_tmp;

	delete bob;
	delete me;
	delete src;
	return 0;
}
