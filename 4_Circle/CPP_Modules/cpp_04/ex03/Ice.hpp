/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 21:27:40 by takwak            #+#    #+#             */
/*   Updated: 2025/05/06 22:28:36 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

#include "AMateria.hpp"

class	Ice : public AMateria {

public:
	Ice();
	virtual ~Ice();
	Ice(const Ice& other);
	Ice& operator=(const Ice& other);

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};
