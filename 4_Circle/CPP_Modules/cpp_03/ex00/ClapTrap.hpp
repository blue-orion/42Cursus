/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 02:02:34 by takwak            #+#    #+#             */
/*   Updated: 2025/04/20 02:02:34 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	ClapTrap {
private:
	std::string		name;
	unsigned int	hitPoint;
	unsigned int	energyPoint;
	unsigned int	attackDamage;
public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap& other);
	ClapTrap(std::string name);

	ClapTrap&	operator=(const ClapTrap& other);

	std::string		getName() const;
	unsigned int	getAttackDamage() const;
	unsigned int	getHitPoint() const;
	unsigned int	getEnergyPoint() const;
	void	setAttackDamage(unsigned int damage);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};
