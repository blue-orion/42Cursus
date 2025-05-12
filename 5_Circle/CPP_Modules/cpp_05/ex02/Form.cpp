/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:10:43 by takwak            #+#    #+#             */
/*   Updated: 2025/05/12 17:10:43 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _isSigned(0), _gradeToSign(0), _gradeToExecute(0) {}
Form::~Form() {}
Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form::Form(const std::string name, const int grade_to_sign, const int grade_to_execute)
	: _name(name), _isSigned(0), _gradeToSign(grade_to_sign), _gradeToExecute(grade_to_execute) {
	if (grade_to_sign > 150 || grade_to_execute > 150) {
		throw Form::GradeTooLowException();
	}
	if (grade_to_sign < 0 || grade_to_execute < 0) {
		throw Form::GradeTooHighException();
	}
}

const std::string&	Form::getName() const {
	return this->_name;
}
int			Form::getIsSigned() const {
	return this->_isSigned;
}
int			Form::getGradeToSign() const {
	return this->_gradeToSign;
}
int			Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = 1;
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}
const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "\n==============================\nname : " << form.getName()
		<< "\nIs signed? : " << form.getIsSigned()
		<< "\ngrade to sing : " << form.getGradeToSign()
		<< "\nGrade to execute : " << form.getGradeToExecute()
		<< "\n==============================" << std::endl;
	return os;
}
