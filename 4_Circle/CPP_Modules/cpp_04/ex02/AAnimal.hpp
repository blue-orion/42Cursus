/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:41:51 by takwak            #+#    #+#             */
/*   Updated: 2025/05/06 02:41:46 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class AAnimal {
protected:
	std::string type;

public:
	AAnimal();
	virtual ~AAnimal();
	AAnimal(const AAnimal &other);
	AAnimal &operator=(const AAnimal &other);

	virtual void makeSound() = 0;
	virtual void makeSound() const = 0;

	std::string getType() const;
};
