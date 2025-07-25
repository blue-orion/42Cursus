/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:18:03 by takwak            #+#    #+#             */
/*   Updated: 2025/05/06 20:59:30 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
private :
	std::string	_name;
	AMateria	*_inventory[4];

public :
	Character();
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();

	Character(const std::string& name);

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};
