/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:41:42 by takwak            #+#    #+#             */
/*   Updated: 2025/05/05 19:41:42 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
	this->type = "Cat";
	std::cout << "Cat constructor" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor" << std::endl;
}

Cat::Cat(const Cat& other) {
	this->type = other.getType();
	std::cout << "Cat constructor by copy" << std::endl;
}

Cat&	Cat::operator=(const Cat& other) {
	if (this == &other)
		return (*this);
	this->type = other.getType();
	return (*this);
}

void	Cat::makeSound() {
	std::cout << "meow~~~" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "meow~~~" << std::endl;
}

WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << "WrongCat constructor" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
	this->type = other.getType();
	std::cout << "WrongCat constructor by copy" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	if (this == &other)
		return (*this);
	this->type = other.getType();
	return (*this);
}

void	WrongCat::makeSound() {
	std::cout << "meow~~~" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "meow~~~" << std::endl;
}
