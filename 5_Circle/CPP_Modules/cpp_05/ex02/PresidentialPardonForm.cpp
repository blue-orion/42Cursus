/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:41:19 by takwak            #+#    #+#             */
/*   Updated: 2025/05/12 21:41:19 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Default", 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name)
	: AForm(name, 25, 5) {}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	this->checkRequirements(executor);

	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
