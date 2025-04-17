/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:55:39 by takwak            #+#    #+#             */
/*   Updated: 2025/04/16 21:49:28 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::add_contact(void)
{
	std::string	input;

	std::cout << "input first name : ";
	std::getline(std::cin, input);
	if (std::cin.eof()) {
		return ;
	}
	while (input.empty()) {
		std::cout << "cannot blink field" << std::endl;
		std::getline(std::cin, input);
	}
	contact[size].set_first_name(input);

	std::cout << "input last name : ";
	std::cin >> input;
	while (input.length() == 0) {
		std::cout << "cannot blink field" << std::endl;
		std::cin >> input;
	}
	contact[size].set_last_name(input);

	std::cout << "input nickname : ";
	std::cin >> input;
	while (input.length() == 0) {
		std::cout << "cannot blink field" << std::endl;
		std::cin >> input;
	}
	contact[size].set_nickname(input);

	std::cout << "input phone number : ";
	std::cin >> input;
	while (input.length() == 0) {
		std::cout << "cannot blink field" << std::endl;
		std::cin >> input;
	}
	contact[size].set_phone_number(input);

	std::cout << "input darkest secret : ";
	std::cin >> input;
	while (input.length() == 0) {
		std::cout << "cannot blink field" << std::endl;
		std::cin >> input;
	}
	contact[size].set_darkest_secret(input);

	this->size++;
}

void	PhoneBook::search_contact(void)
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
	while (std::cin.fail()) {
		std::cout << "Is not a number" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> index;
	}
	if (index - 1 > size) {
		std::cout << "Not Exist, stop searching" << std::endl;
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

int	PhoneBook::get_size(void) {
	return (this->size);
}
