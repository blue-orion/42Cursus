/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 02:21:59 by takwak            #+#    #+#             */
/*   Updated: 2025/05/05 17:18:24 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
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
	ClapTrap	B("B");
	print_attributes(B);
	print_nl();
	
	A.attack(B.getName());
	B.takeDamage(A.getAttackDamage());
	print_nl();

	for (int i = 0; i < 10; i++) {
		A.beRepaired(10);
	}

}
