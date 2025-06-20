/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:18:15 by takwak            #+#    #+#             */
/*   Updated: 2025/05/14 19:20:34 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: ./convert [string to convert]" << std::endl;
		return -1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}
