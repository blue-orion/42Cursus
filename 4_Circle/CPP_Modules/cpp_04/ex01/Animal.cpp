/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:41:50 by takwak            #+#    #+#             */
/*   Updated: 2025/05/05 22:41:59 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
	std::cout << "Default Animal constructer" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor" << std::endl;
}

Animal::Animal(const Animal& other) {
	std::cout << "Animal constructer by copy" << std::endl;
	this->type = other.getType();
}

Animal&	Animal::operator=(const Animal& other) {
	if (this == &other)
		return (*this);
	this->type = other.getType();
	return (*this);
}

std::string	Animal::getType() const {
	return (this->type);
}

void	Animal::makeSound() {
	std::cout << "grrr..." << std::endl;
}

void	Animal::makeSound() const {
	std::cout << "grrr..." << std::endl;
}
