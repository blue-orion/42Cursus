/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:16:13 by takwak            #+#    #+#             */
/*   Updated: 2025/05/13 18:17:19 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat {
private:
	const std::string	name;
	int					grade;

	const Bureaucrat& operator=(const Bureaucrat& other);

public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);

	Bureaucrat(const std::string name, int grade);

	const std::string & getName() const;
	int					getGrade() const;
	void				setGrade(int grade);
	void				upGrade(int grade);
	void				downGrade(int grade);

	void	signForm(AForm& form);
	void	executeForm(AForm const & form);

	class GradeTooHighException : public std::exception {
		virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char*	what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
