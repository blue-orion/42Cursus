/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:41:19 by takwak            #+#    #+#             */
/*   Updated: 2025/05/14 18:03:32 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5, "Default") {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute(), other.getTarget()) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name)
	: AForm("PresidentialPardonForm", 25, 5, name) {}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	this->checkRequirements(executor);

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
