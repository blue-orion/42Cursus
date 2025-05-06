/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:47:16 by takwak            #+#    #+#             */
/*   Updated: 2025/05/06 02:42:30 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal {
private:
	Brain	*brain;

public:
	Dog();
	virtual ~Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);

	virtual void	makeSound() const;

	void	thinking(std::string content);
	std::string	speaking(int index);
};
