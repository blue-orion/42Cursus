/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:38:25 by takwak            #+#    #+#             */
/*   Updated: 2025/04/22 00:10:50 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl() {
	funcPtr = &Harl::debug;
};

void	Harl::debug(void) {
	std::cout << "[DEBUG]\n"
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
		<< "I really do!\n" << std::endl;
}
void	Harl::info(void) {
	std::cout << "[INFO]\n"
		<< "I cannot believe adding extra bacon costs more money.\n"
		<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}
void	Harl::warning(void) {
	std::cout << "[WARNING]\n"
		<< "I think I deserve to have some extra bacon for free.\n"
		<< "I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}
void	Harl::error(void) {
	std::cout << "[ERROR]\n"
		<< "This is unacceptable!\n"
		<< "I want to speak to the manager now.\n" << std::endl;
}

void	Harl::complain(std::string level) {
	int input = 1 * (level == "DEBUG") + 2 * (level == "INFO") +
				3 * (level == "WARNING") + 4 * (level == "ERROR");

	funcPtr = &Harl::debug;
	switch (input) {
		case 1:
			Harl::debug();
			break ;
		case 2:
			this->info();
			break;
		case 3:
			warning();
			break;
		case 4:
			error();
			break;
		default:
			break;
	}
}
