/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:41:47 by takwak            #+#    #+#             */
/*   Updated: 2025/05/05 22:41:42 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal {
private:
	Brain	*brain;

public:
	Cat();
	virtual ~Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);

	virtual void	makeSound() const;

	void	thinking(std::string content);
};
