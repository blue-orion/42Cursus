/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 02:21:59 by takwak            #+#    #+#             */
/*   Updated: 2025/05/06 01:36:49 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

void	print_nl() {
	std::cout << std::endl;
}

void	print_attributes(ClapTrap &obj) {
	std::cout << "== " << obj.getName() << " attributes ==\n"
		<< "HitPoint = " << obj.getHitPoint() << std::endl
		<< "EnergyPoint = " << obj.getEnergyPoint() << std::endl
		<< "AttackDamage = " << obj.getAttackDamage() << std::endl;
}

int	main(void) {
	ClapTrap	A("A");
	print_attributes(A);
	print_nl();
	ScavTrap	B("B");
	print_attributes(B);
	print_nl();
	FragTrap	C("C");
	print_attributes(C);
	print_nl();
	DiamondTrap	D("D");
	print_attributes(D);
	print_nl();

	A.attack("B");
	B.takeDamage(A.getAttackDamage());
	print_nl();

	B.attack("A");
	A.takeDamage(B.getAttackDamage());
	A.beRepaired(50);
	print_nl();

	B.guardGate();
	print_nl();

	C.highFivesGuys();
	print_nl();

	D.whoAmI();
	print_nl();
	D.guardGate();
	print_nl();
	D.highFivesGuys();
	print_nl();
	D.attack("C");
	C.takeDamage(D.getAttackDamage());
	print_nl();
}
