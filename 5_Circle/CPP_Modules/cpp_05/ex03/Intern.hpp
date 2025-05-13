/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:35:18 by takwak            #+#    #+#             */
/*   Updated: 2025/05/13 15:14:18 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <string>
#include "AForm.hpp"

class Intern {
private:
	const static int	_formNum = 3;
	AForm				*(Intern::*_fnptr[_formNum])(const std::string &target);
	std::string			_formNames[_formNum];

	Intern(const Intern& other);
	const Intern& operator=(const Intern& other);

public:
	Intern();
	virtual ~Intern();

	AForm	*makeForm(const std::string &formName, const std::string& target);
	AForm	*makeShrubberyCraetionForm(const std::string &target);
	AForm	*makeRobotomyRequestForm(const std::string &target);
	AForm	*makePresidentialPardonForm(const std::string &target);

	class NoExistFormName : public std::exception {
		virtual const char *what() const throw();
	};
};
