/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:38:25 by takwak            #+#    #+#             */
/*   Updated: 2025/05/04 18:13:28 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl() {
	funcPtr[0] = &Harl::debug;
	funcPtr[1] = &Harl::info;
	funcPtr[2] = &Harl::warning;
	funcPtr[3] = &Harl::error;
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
	int input = 0 * (level == "DEBUG") + 1 * (level == "INFO") +
				2 * (level == "WARNING") + 3 * (level == "ERROR");
	(this->*funcPtr[input])();
}
