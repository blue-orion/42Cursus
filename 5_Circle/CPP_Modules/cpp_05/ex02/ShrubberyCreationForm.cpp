/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:17:47 by takwak            #+#    #+#             */
/*   Updated: 2025/05/12 21:17:47 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Default", 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name)
	: AForm(name, 145, 137) {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	this->checkRequirements(executor);

	std::string	name = this->getName() + "_shrubbery";
	std::ofstream	ofs(name.c_str());

	ofs << "              v .   ._, |_  .,\n"
	<< "           `-._\\/  . \\ /    |/_\n"
	<< "               \\  _\\, y | \\//\n"
	<< "         _\\_.___\\, \\/ -.\\||\n"
	<< "           `7-,--.`._||  / / ,\n"
	<< "           /'     `-. `./ / |/_.'\n"
	<< "                     |_    /\n"
	<< "                     |-   |\n"
	<< "                     |   =|\n"
	<< "                     |    |\n"
	<< "--------------------/ ,  . \\--------._\n";
	ofs.close();
}
