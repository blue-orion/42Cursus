/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:16:11 by takwak            #+#    #+#             */
/*   Updated: 2025/05/14 17:47:04 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main(void) {
	try {
		Bureaucrat	b("takwak2", 100);
		std::cout << b << std::endl;

		std::cout << "try to initiate grade 200" << std::endl;
		Bureaucrat	c("takwak3", 200);

		std::cout << "try to make grade 0" << std::endl;
		b.setGrade(0);

		std::cout << "try to make grade 101" << std::endl;
		b.downGrade(1);

		std::cout << "try to make grade -50" << std::endl;
		b.upGrade(150);
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}
