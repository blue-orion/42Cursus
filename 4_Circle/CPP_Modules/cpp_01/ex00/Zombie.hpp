/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:59:28 by takwak            #+#    #+#             */
/*   Updated: 2025/04/18 00:59:28 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	Zombie {
private:
	std::string	name;

public:
	Zombie( std::string name );
	~Zombie( void );

	void	announce( void );
};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

# endif
