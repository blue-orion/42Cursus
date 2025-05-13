/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:37:31 by takwak            #+#    #+#             */
/*   Updated: 2025/05/12 21:37:31 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	const RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

public:
	RobotomyRequestForm();
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& other);

	RobotomyRequestForm(const std::string &name);
	virtual void	execute(Bureaucrat const & executor) const;
};
