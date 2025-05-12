/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:47:37 by takwak            #+#    #+#             */
/*   Updated: 2025/05/12 16:47:37 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

	const Form& operator=(const Form& other);

public:
	Form();
	~Form();
	Form(const Form& other);

	Form(const std::string name, const int grade_to_sign, const int grade_to_execute);

	const std::string&	getName() const;
	int			getIsSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	void	beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);
