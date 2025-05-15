/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:28:47 by takwak            #+#    #+#             */
/*   Updated: 2025/05/15 19:53:49 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base::~Base() {}

Base	*generate(void) {
	int	random;

	srand(time(NULL));
	random = rand() % 3;
	if (random == 0) {
		return dynamic_cast<Base*>(new A());
	}
	if (random == 1) {
		return dynamic_cast<Base*>(new B());
	}
	if (random == 2) {
		return dynamic_cast<Base*>(new C());
	}
	return NULL;
}

void	identify(Base *p) {
	void	*ptr;

	ptr = dynamic_cast<A*>(p);
	if (ptr)
		std::cout << "A" << std::endl;
	ptr = dynamic_cast<B*>(p);
	if (ptr)
		std::cout << "B" << std::endl;
	ptr = dynamic_cast<C*>(p);
	if (ptr)
		std::cout << "C" << std::endl;
}

void	identify(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception &e) {}
}
