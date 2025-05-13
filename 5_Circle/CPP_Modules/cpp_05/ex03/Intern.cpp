/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:41:54 by takwak            #+#    #+#             */
/*   Updated: 2025/05/13 15:10:06 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	Intern::_fnptr[0] = &Intern::makeShrubberyCraetionForm;
	Intern::_fnptr[1] = &Intern::makeRobotomyRequestForm;
	Intern::_fnptr[2] = &Intern::makePresidentialPardonForm;

	_formNames[0] = "shrubbery creation";
	_formNames[1] = "robotomy request";
	_formNames[2] = "presidential pardon";
}

Intern::~Intern() {}

const char *Intern::NoExistFormName::what() const throw() {
	return "Form name does not exist";
}

AForm	*Intern::makeShrubberyCraetionForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::makeRobotomyRequestForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

AForm	*Intern::makePresidentialPardonForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(const std::string &formName, const std::string& target) {
	for (int i = 0; i < _formNum; i++) {
		if (formName == _formNames[i])
			return (this->*_fnptr[i])(target);
	}
	throw Intern::NoExistFormName();
};
