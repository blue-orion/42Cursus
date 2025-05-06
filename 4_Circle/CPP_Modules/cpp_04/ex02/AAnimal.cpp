/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:41:50 by takwak            #+#    #+#             */
/*   Updated: 2025/05/06 02:41:55 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() {
	std::cout << "Default AAnimal constructer" << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
	std::cout << "AAnimal constructer by copy" << std::endl;
	this->type = other.getType();
}

AAnimal&	AAnimal::operator=(const AAnimal& other) {
	if (this == &other)
		return (*this);
	this->type = other.getType();
	return (*this);
}

std::string	AAnimal::getType() const {
	return (this->type);
}

void	AAnimal::makeSound() const {
	std::cout << "grrr..." << std::endl;
}
