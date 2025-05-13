/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:40:34 by takwak            #+#    #+#             */
/*   Updated: 2025/05/12 21:40:34 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	const PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

public:
	PresidentialPardonForm();
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& other);

	PresidentialPardonForm(const std::string &name);
	virtual void	execute(Bureaucrat const & executor) const;
};
