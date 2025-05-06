/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:41:47 by takwak            #+#    #+#             */
/*   Updated: 2025/05/05 19:41:47 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class	Cat : public Animal {
public:
	Cat();
	~Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);

	virtual void	makeSound() const;
};

class	WrongCat : public WrongAnimal {
public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat& other);
	WrongCat& operator=(const WrongCat& other);

	void	makeSound() const;
};
