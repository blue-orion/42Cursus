/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 02:21:59 by takwak            #+#    #+#             */
/*   Updated: 2025/04/20 02:21:59 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void) {
	ClapTrap	A("A");
	ClapTrap	B("B");

	A.setAttackDamage(5);
	A.attack(B.getName());
	B.takeDamage(A.getAttackDamage());
	B.beRepaired(3);
	B.beRepaired(3);
	B.beRepaired(3);
	A.attack(B.getName());
	B.takeDamage(A.getAttackDamage());
	B.beRepaired(3);
	B.beRepaired(3);
	A.attack(B.getName());
	B.takeDamage(A.getAttackDamage());
	B.beRepaired(3);
	B.beRepaired(3);
	A.attack(B.getName());
	B.takeDamage(A.getAttackDamage());
	A.attack(B.getName());
	B.takeDamage(A.getAttackDamage());
	A.attack(B.getName());
	B.takeDamage(A.getAttackDamage());
	A.attack(B.getName());
	B.takeDamage(A.getAttackDamage());
	B.attack("A");
	A.takeDamage(B.getAttackDamage());
}
