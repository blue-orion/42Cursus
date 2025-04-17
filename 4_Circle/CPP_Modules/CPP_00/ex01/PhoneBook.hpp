/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:47:11 by takwak            #+#    #+#             */
/*   Updated: 2025/04/16 21:49:26 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <limits>
# include <iomanip>

class PhoneBook {
private:
	Contact contact[8];
	int		size;

public:
	PhoneBook() {
		size = 0;
	}

	void	add_contact(void);
	void	search_contact(void);
	int		get_size(void);
};

#endif
