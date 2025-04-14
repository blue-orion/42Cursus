/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:47:11 by takwak            #+#    #+#             */
/*   Updated: 2025/04/14 17:07:23 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.h"
# include <iostream>

class PhoneBook {
private:
	Contact contact[8];
	int		num;

public:
	PhoneBook(void) {
		std::cout << "PhoneBook created" << std::endl;
	}

	~PhoneBook(void) {
		std::cout << "PhoneBook deleted" << std::endl;
	}

	PhoneBook(const PhoneBook& other) {
		num = other.num;
		for (int i = 0; i < 8; i++) {
			contact[i] = other.contact[i];
		}
	}

	void set_contact(char *first_name, char *last_name, char *nickname,
			char *phone_num, char *darkest_secret) {
		
	}
};

#endif
