/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:30:59 by takwak            #+#    #+#             */
/*   Updated: 2025/05/06 22:34:05 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource {
private:
	AMateria	*_inventory[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);

	virtual ~MateriaSource();
	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
};
