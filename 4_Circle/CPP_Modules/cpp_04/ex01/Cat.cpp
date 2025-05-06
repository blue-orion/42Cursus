/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:41:42 by takwak            #+#    #+#             */
/*   Updated: 2025/05/06 02:05:20 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
	std::cout << "Cat constructor" << std::endl;
	this->type = "Cat";
	brain = new Brain;
}

Cat::~Cat() {
	std::cout << "Cat destructor" << std::endl;
	delete brain;
}

Cat::Cat(const Cat& other) {
	std::cout << "Cat constructor by copy" << std::endl;
	this->type = other.getType();
	brain = new Brain;
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(other.brain->getIdea(i));
}

Cat&	Cat::operator=(const Cat& other) {
	if (this == &other)
		return (*this);
	this->type = other.getType();

	delete this->brain;
	this->brain = new Brain;
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(other.brain->getIdea(i));

	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "meow~~~" << std::endl;
}

void	Cat::thinking(std::string content) {
	this->brain->setIdea(content);
}
