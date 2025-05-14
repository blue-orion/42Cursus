/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:40:19 by takwak            #+#    #+#             */
/*   Updated: 2025/05/14 18:05:13 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45, "Default") {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute(), other.getTarget()) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name)
	: AForm("RobotomyRequestForm", 72, 45, name) {}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	this->checkRequirements(executor);

	std::cout << "* VRRRRRRRRRRRR... BZZZZZTTT! *" << std::endl;

	srand(time(NULL));

	if (rand() % 100 < 50)
		std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << this->getTarget() << " has been robotomized failed..." << std::endl;
}
