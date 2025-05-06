/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:41:51 by takwak            #+#    #+#             */
/*   Updated: 2025/05/05 19:41:51 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Animal {
protected:
	std::string	type;

public:
	Animal();
	virtual ~Animal();
	Animal(const Animal& other);
	Animal&	operator=(const Animal& other);

	virtual void	makeSound() const;

	std::string	getType() const;
};

class	WrongAnimal {
protected:
	std::string	type;

public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal&	operator=(const WrongAnimal& other);

	void	makeSound() const;

	std::string	getType() const;
};
