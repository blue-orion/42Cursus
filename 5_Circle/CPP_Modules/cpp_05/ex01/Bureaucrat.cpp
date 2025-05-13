/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:16:12 by takwak            #+#    #+#             */
/*   Updated: 2025/05/13 18:15:53 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() {}
Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) 
	: name(other.name), grade(other.grade) {

	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
	: name(name), grade(grade) {

	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

const std::string&	Bureaucrat::getName() const {
	return this->name;
}

int	Bureaucrat::getGrade() const {
	return this->grade;
}

void	Bureaucrat::setGrade(int grade) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
}

void	Bureaucrat::upGrade(int grade) {
	if (this->grade - grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade -= grade;
}

void	Bureaucrat::downGrade(int grade) {
	if (this->grade + grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade += grade;
}

void	Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form;
	}
	catch (std::exception& e) {
		std::cout << this->getName() << " couldn't sign " << form 
			<< "because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";

	return os;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}
const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}
