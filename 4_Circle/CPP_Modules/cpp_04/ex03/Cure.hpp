/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:20:37 by takwak            #+#    #+#             */
/*   Updated: 2025/05/06 22:28:31 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

#include "AMateria.hpp"

class	Cure : public AMateria {

public:
	Cure();
	virtual ~Cure();
	Cure(const Cure& other);
	Cure& operator=(const Cure& other);

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};
