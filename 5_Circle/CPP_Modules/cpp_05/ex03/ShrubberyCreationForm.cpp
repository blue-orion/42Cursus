/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:17:47 by takwak            #+#    #+#             */
/*   Updated: 2025/05/14 18:05:49 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137, "Default") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute(), other.getTarget()) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name)
	: AForm("ShrubberyCreationForm", 145, 137, name) {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	this->checkRequirements(executor);

	std::string	name = this->getTarget() + "_shrubbery";
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
