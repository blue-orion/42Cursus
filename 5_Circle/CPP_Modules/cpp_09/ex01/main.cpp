/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 23:11:05 by takwak            #+#    #+#             */
/*   Updated: 2025/05/28 23:11:05 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main(int ac, char **av) {
	if (ac < 2 || ac > 2) {
		std::cerr << "Usage: ./RPN [postfix expression]" << std::endl;
		return 1;
	}
	RPN	rpn;
	int	result;

	try {
		result = rpn.evalExpression(av[1]);
		std::cout << result << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
