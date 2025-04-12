/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:47:11 by takwak            #+#    #+#             */
/*   Updated: 2025/04/13 00:49:24 by takwak           ###   ########.fr       */
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
	PhoneBook(void)
	{
		std::cout << "PhoneBook created" << std::endl;
	}
	~PhoneBook(void)
	{
		std::cout << "PhoneBook deleted" << std::endl;
	}

	void set_contact(char *first_name, char *last_name, char *nickname, char *phone_num, char *darkest_secret)
	{
		
	}
};

#endif
