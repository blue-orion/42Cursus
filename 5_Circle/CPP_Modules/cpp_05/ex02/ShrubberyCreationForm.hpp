/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:09:43 by takwak            #+#    #+#             */
/*   Updated: 2025/05/12 21:11:51 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	const ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

public:
	ShrubberyCreationForm();
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& other);

	ShrubberyCreationForm(const std::string &name);
	virtual void	execute(Bureaucrat const & executor) const;
};
