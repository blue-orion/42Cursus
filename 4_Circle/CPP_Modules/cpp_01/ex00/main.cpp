/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 01:15:41 by takwak            #+#    #+#             */
/*   Updated: 2025/04/18 01:15:41 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie	*heap_zombie;
	
	randomChump("func stack");

	Zombie	stack("main stack");
	stack.announce();

	heap_zombie = newZombie("heap");
	heap_zombie->announce();

	delete heap_zombie;
}
