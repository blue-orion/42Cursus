/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:47:11 by takwak            #+#    #+#             */
/*   Updated: 2025/05/04 16:28:19 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
private:
	Contact contact[8];
	int		add_count;
	int		index;

public:
	PhoneBook() {
		add_count = 0;
		index = 0;
	}

	void	AddContact(void);
	void	SearchContact(void);
	void	DisplayPhoneBook(void);
};

#endif
