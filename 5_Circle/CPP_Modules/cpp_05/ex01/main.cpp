/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:16:11 by takwak            #+#    #+#             */
/*   Updated: 2025/05/12 15:16:11 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void) {
	try {
		Bureaucrat	b("takwak1", 100);
		std::cout << b << std::endl;

		Form	form("form1", 50, 50);
		b.signForm(form);

		std::cout << std::endl;

		Bureaucrat	c("takwak2", 10);
		std::cout << c << std::endl;
		c.signForm(form);
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}
