/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:10:43 by takwak            #+#    #+#             */
/*   Updated: 2025/05/14 18:02:18 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(0), _gradeToSign(0), _gradeToExecute(0) {}
AForm::~AForm() {}
AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm::AForm(const std::string name, const int grade_to_sign, const int grade_to_execute, const std::string target)
	: _name(name), _isSigned(0), _gradeToSign(grade_to_sign), _gradeToExecute(grade_to_execute), _target(target) {
	if (grade_to_sign > 150 || grade_to_execute > 150) {
		throw AForm::GradeTooLowException();
	}
	if (grade_to_sign < 0 || grade_to_execute < 0) {
		throw AForm::GradeTooHighException();
	}
}

const std::string&	AForm::getName() const {
	return this->_name;
}
int			AForm::getIsSigned() const {
	return this->_isSigned;
}
int			AForm::getGradeToSign() const {
	return this->_gradeToSign;
}
int			AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

const std::string&	AForm::getTarget() const {
	return this->_target;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = 1;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::checkRequirements(Bureaucrat const & bureaucrat) const {
	if (this->_isSigned)
		throw AForm::AlreadySignedException();
	if (bureaucrat.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}
const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}
const char* AForm::AlreadySignedException::what() const throw() {
	return "This form is already signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "\n==============================\nname : " << form.getName()
		<< "\nIs signed? : " << form.getIsSigned()
		<< "\ngrade to sign : " << form.getGradeToSign()
		<< "\nGrade to execute : " << form.getGradeToExecute()
		<< "\n==============================" << std::endl;
	return os;
}
