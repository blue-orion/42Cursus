/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:47:11 by takwak            #+#    #+#             */
/*   Updated: 2025/04/17 22:06:24 by takwak           ###   ########.fr       */
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
	int		max_size;
	int		index;

public:
	PhoneBook() {
		max_size = 0;
		index = 0;
	}

	void	AddContact(void);
	void	SearchContact(void);
	void	DisplayPhoneBook(void);
};

#endif
