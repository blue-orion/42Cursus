/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:44:36 by takwak            #+#    #+#             */
/*   Updated: 2025/05/04 16:22:19 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	phone_book;
	std::string	input;

	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		if (input == "ADD")
			phone_book.AddContact();
		else if (input == "SEARCH")
			phone_book.SearchContact();
		else if (input == "EXIT")
			break ;
		else {
			std::cout << "invalid input" << std::endl;
			std::cout << "You can ADD, SEARCH, EXIT" << std::endl;
		}
	}
	return 0;
}
