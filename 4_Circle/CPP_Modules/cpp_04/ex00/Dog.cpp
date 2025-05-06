/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:47:36 by takwak            #+#    #+#             */
/*   Updated: 2025/05/05 19:47:36 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
	this->type = "Dog";
	std::cout << "Dog constructor" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor" << std::endl;
}

Dog::Dog(const Dog& other) {
	this->type = other.getType();
	std::cout << "Dog constructor by copy" << std::endl;
}

Dog&	Dog::operator=(const Dog& other) {
	if (this == &other)
		return (*this);
	this->type = other.getType();
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "bark!!!" << std::endl;
}
