/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:47:37 by takwak            #+#    #+#             */
/*   Updated: 2025/05/14 18:02:00 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	const std::string	_target;

	const AForm& operator=(const AForm& other);

public:
	AForm();
	virtual ~AForm();
	AForm(const AForm& other);

	AForm(const std::string name, const int grade_to_sign, const int grade_to_execute, const std::string target);

	const std::string&	getName() const;
	int					getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	const std::string&	getTarget() const;

	void			beSigned(const Bureaucrat& bureaucrat);
	virtual void	execute(Bureaucrat const & executor) const = 0;
	void			checkRequirements(Bureaucrat const & executor) const;

	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw();
	};
	class AlreadySignedException : public std::exception {
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
