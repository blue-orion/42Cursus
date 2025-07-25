/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:48:45 by takwak            #+#    #+#             */
/*   Updated: 2025/05/28 21:06:46 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>

int	main(int ac, char **av) {
	(void)ac;
	try {
		BitcoinExchange	btc;

		btc.makeResults(av[1]);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
