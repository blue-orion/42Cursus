/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:51:53 by takwak            #+#    #+#             */
/*   Updated: 2025/04/18 21:51:53 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	Harl	harl;

	if (argc != 2) {
		std::cerr << "Usage: ./harlFilter [LEVEL]\n"
			<< "Yon can input: DEBUG, INFO, WARNING, ERROR"<< std::endl;
		return 1;
	}
	harl.complain(argv[1]);
	return 0;
}
