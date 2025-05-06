/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:47:36 by takwak            #+#    #+#             */
/*   Updated: 2025/05/06 02:29:00 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
	std::cout << "Dog constructor" << std::endl;
	this->type = "Dog";
	this->brain = new Brain;
}

Dog::~Dog() {
	std::cout << "Dog destructor" << std::endl;
	delete brain;
}

Dog::Dog(const Dog& other) {
	std::cout << "Dog constructor by copy" << std::endl;
	this->type = other.getType();
	this->brain = new Brain;
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(other.brain->getIdea(i));
}

Dog&	Dog::operator=(const Dog& other) {
	if (this == &other)
		return (*this);
	this->type = other.getType();

	delete(this->brain);
	this->brain = new Brain;
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(other.brain->getIdea(i));
	
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "bark!!!" << std::endl;
}

void	Dog::thinking(std::string content) {
	this->brain->setIdea(content);
}

std::string	Dog::speaking(int index) {
	return this->brain->getIdea(index);
}
