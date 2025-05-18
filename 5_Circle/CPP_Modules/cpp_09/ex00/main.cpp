/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:48:45 by takwak            #+#    #+#             */
/*   Updated: 2025/05/18 18:41:54 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: ./btc [data.csv]" << std::endl;
		return 1;
	}
	BitcoinExchange	btc;

	try {
		btc.saveDataFromFile(av[1]);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	btc.printData();
	return 0;
}
