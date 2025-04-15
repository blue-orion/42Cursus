/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:55:39 by takwak            #+#    #+#             */
/*   Updated: 2025/04/15 22:44:02 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

int	main(void)
{
	PhoneBook	phone_book;
	std::string	input;

	while (1)
	{
		std::cin >> input;
		if (!input.compare("ADD"))
		{
			phone_book.add_contact();
			std::cout << input << std::endl;
		}
		else if (!input.compare("SEARCH"))
		{
			phone_book.search_contact();
			std::cout << input << std::endl;
		}
		else if (!input.compare("EXIT"))
		{
			std::cout << input << std::endl;
			break ;
		}
		else
			std::cout << "invalid input" << std::endl;
	}
}
