/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:47:11 by takwak            #+#    #+#             */
/*   Updated: 2025/04/15 23:49:44 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.h"
# include <iostream>
# include <iomanip>

class PhoneBook {
private:
	Contact contact[8];
	int		size;

public:
	PhoneBook() {
		size = 0;
	}

	void	add_contact(void)
	{
		std::string	input;

		std::cout << "input first name" << std::endl;
		std::cin >> input;
		contact[size].set_first_name(input);

		std::cout << "input last name" << std::endl;
		std::cin >> input;
		contact[size].set_last_name(input);

		std::cout << "input nickname" << std::endl;
		std::cin >> input;
		contact[size].set_nickname(input);

		std::cout << "input phone number" << std::endl;
		std::cin >> input;
		contact[size].set_phone_number(input);

		std::cout << "input darkest secret" << std::endl;
		std::cin >> input;
		contact[size].set_darkest_secret(input);

		this->size++;
	}

	void	search_contact(void)
	{
		std::string	tmp;

		for (int i = 0; i < size; i++) {
			std::cout << std::right << std::setw(10) << i + 1 << "|";
			
			tmp = contact[i].get_first_name();
			if (tmp.length() > 10)
				tmp = tmp.substr(0, 9) + ".";
			std::cout << std::right << std::setw(10) << tmp << "|";
			
			tmp = contact[i].get_last_name();
			if (tmp.length() > 10)
				tmp = tmp.substr(0, 9) + ".";
			std::cout << std::right << std::setw(10) << tmp << "|";

			tmp = contact[i].get_nickname();
			if (tmp.length() > 10)
				tmp = tmp.substr(0, 9) + ".";
			std::cout << std::right << std::setw(10) << tmp << std::endl;
		}

		int	index;

		std::cout << "Enter index : ";
		std::cin >> index;
		
		if (index - 1 > size) {
			std::cout << "Not Exist" << std::endl;
		}
		else {
			std::cout << index << std::endl
				<< "first name : " << contact[index - 1].get_first_name() << std::endl
				<< "last name : " << contact[index - 1].get_last_name() << std::endl
				<< "nickname : " << contact[index - 1].get_nickname() << std::endl
				<< "phone number : " << contact[index - 1].get_phone_number() << std::endl
				<< "darkest secret : " << contact[index - 1].get_darkest_secret() << std::endl;
		}
	}

	int	get_size(void) {
		return (this->size);
	}
};

#endif
