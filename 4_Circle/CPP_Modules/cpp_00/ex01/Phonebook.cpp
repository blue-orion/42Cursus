/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:55:39 by takwak            #+#    #+#             */
/*   Updated: 2025/05/04 16:29:30 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdio>
#include <limits>
#include <iostream>
#include <iomanip>

std::string	InputString(const char *field_name)
{
	std::string	input;

	std::cout << "Input " << field_name << " : ";
	std::getline(std::cin, input);
	if (std::cin.eof()) {
		return NULL;
	}
	while (input.empty()) {
		std::cout << "Cannot input blink field" << std::endl;
		std::cout << "Input " << field_name << " : ";
		std::getline(std::cin, input);
	}
	return input;
}

void	PhoneBook::AddContact(void)
{
	std::string	input;

	if (add_count >= 8)
	{
		std::cout << "PhoneBook max, Delete and add contact" << std::endl;
		this->index = add_count % 8;
	}

	input = InputString("fisrt name");
	contact[index].SetFirstName(input);

	input = InputString("last name");
	contact[index].SetLastName(input);

	input = InputString("nickname");
	contact[index].SetNickname(input);

	input = InputString("phone number");
	contact[index].SetPhoneNumber(input);

	input = InputString("darkest secret");
	contact[index].SetDarkestSecret(input);

	std::cout << "Complete!" << std::endl;
	this->index++;
	this->add_count++;
}

void	PhoneBook::DisplayPhoneBook(void)
{
	std::string	tmp;
	int			size;

	std::cout << "=============================================" << std::endl
		<< "|" << std::right << std::setw(10) << "Index" << "|" 
		<< std::right << std::setw(10) << "First name" << "|" 
		<< std::right << std::setw(10) << "Last name" << "|" 
		<< std::right << std::setw(10) << "Nickname" << "|" << std::endl
		<< "=============================================" << std::endl;

	size = add_count > 8 ? 8 : add_count;
	for (int i = 0; i < size; i++) {
		std::cout << "|";
		std::cout << std::right << std::setw(10) << i + 1 << "|";
		
		tmp = contact[i].GetFirstName();
		if (tmp.length() > 10)
			tmp = tmp.substr(0, 9) + ".";
		std::cout << std::right << std::setw(10) << tmp << "|";
		
		tmp = contact[i].GetLastName();
		if (tmp.length() > 10)
			tmp = tmp.substr(0, 9) + ".";
		std::cout << std::right << std::setw(10) << tmp << "|";

		tmp = contact[i].GetNickname();
		if (tmp.length() > 10)
			tmp = tmp.substr(0, 9) + ".";
		std::cout << std::right << std::setw(10) << tmp << "|" << std::endl;
		if (i != add_count - 1)
			std::cout << "---------------------------------------------" << std::endl;
	}

	std::cout << "=============================================" << std::endl;
}

void	OpenNewStream() {
	std::cin.clear();
	std::cout << std::endl;
	freopen("/dev/tty", "r", stdin);
}

void	PhoneBook::SearchContact(void)
{
	DisplayPhoneBook();

	int	index;

	while (1)
	{
		std::cout << "Enter index : ";
		std::cin >> index;
		if (std::cin.eof()) {
			return OpenNewStream();
		}
		if (std::cin.fail()) {
			std::cout << "Is not a number" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break ;
		}
	}
	if (index <= 0 || index > (add_count > 8 ? 8 : add_count)) {
		std::cout << "Not Exist, stop searching" << std::endl;
		return ;
	}
	std::cout << "=============================================" << std::endl;
	std::cout << "No. " << index << std::endl;
	contact[index - 1].print();
	std::cout << "=============================================" << std::endl;
}
