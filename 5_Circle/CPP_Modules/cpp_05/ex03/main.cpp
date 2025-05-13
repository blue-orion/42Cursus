/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:16:11 by takwak            #+#    #+#             */
/*   Updated: 2025/05/13 15:20:57 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main(void) {
	ShrubberyCreationForm shrubForm("shrubbery");
	RobotomyRequestForm	robotoForm("Roboto");
	PresidentialPardonForm presidentForm("presidential");

	Bureaucrat	b("takwak1", 140);
	std::cout << b << std::endl;
	std::cout << std::endl;

	Bureaucrat	c("takwak2", 10);
	std::cout << c << std::endl;
	std::cout << std::endl;

	Bureaucrat	d("takwak3", 1);
	std::cout << d << std::endl;
	std::cout << std::endl;

	Intern someRandomIntern;
	AForm* rrf;
	AForm* ppf;
	AForm* scf;

	try {
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << std::endl;
		d.executeForm(*rrf);
		delete rrf;

		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << std::endl;
		d.executeForm(*ppf);
		delete ppf;

		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		std::cout << std::endl;
		d.executeForm(*scf);
		delete scf;

		std::cout << std::endl;

		scf = someRandomIntern.makeForm("do not exist", "Bender");
		std::cout << std::endl;
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}
