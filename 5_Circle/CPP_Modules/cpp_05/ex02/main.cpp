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
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main(void) {
	try {
		ShrubberyCreationForm shrubForm("shrubbery");
		RobotomyRequestForm	robotoForm("Roboto");
		PresidentialPardonForm presidentForm("presidential");

		Bureaucrat	b("takwak1", 140);
		std::cout << b << std::endl;
		std::cout << std::endl;

		b.executeForm(shrubForm);
		std::cout << std::endl;
		b.executeForm(robotoForm);
		std::cout << std::endl;
		b.executeForm(presidentForm);
		std::cout << std::endl;

		std::cout << std::endl;

		Bureaucrat	c("takwak2", 10);
		std::cout << c << std::endl;
		std::cout << std::endl;
		c.executeForm(shrubForm);
		std::cout << std::endl;
		c.executeForm(robotoForm);
		std::cout << std::endl;
		c.executeForm(presidentForm);

		std::cout << std::endl;
		c.signForm(shrubForm);
		std::cout << std::endl;

		Bureaucrat	d("takwak3", 1);
		std::cout << d << std::endl;
		std::cout << std::endl;
		d.executeForm(shrubForm);
		std::cout << std::endl;
		d.executeForm(robotoForm);
		std::cout << std::endl;
		d.executeForm(presidentForm);
		std::cout << std::endl;

		Bureaucrat	e("takwak4", 0);
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}
