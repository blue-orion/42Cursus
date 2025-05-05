/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:36:12 by takwak            #+#    #+#             */
/*   Updated: 2025/05/06 01:56:31 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain constructor" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "";
	this->index = 0;
}

Brain::~Brain() {
	std::cout << this << " Brain destructor" << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other) {
	if (this == &other)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return (*this);
}

void	Brain::setIdea(std::string content) {
	this->ideas[this->index++] = content;
}

std::string	Brain::getIdea(int index) const {
	if (index < 0 || index >= 100) {
		std::cout << "Invalid index number" << std::endl;
	}
	return (this->ideas[index]);
}
