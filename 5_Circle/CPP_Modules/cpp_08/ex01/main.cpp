/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:57:09 by takwak            #+#    #+#             */
/*   Updated: 2025/05/17 01:39:21 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	{
		std::cout << "Test in subject" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.print();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		std::cout << std::endl << "Test 10,000 elements" << std::endl;
		std::srand(std::time(NULL));
		Span	bigsp = Span(10000);
		for (int i = 0; i < 10000; i++) {
			bigsp.addNumber(static_cast<int>(std::rand()));
		}
		try {
			std::cout << bigsp.shortestSpan() << std::endl;
			std::cout << bigsp.longestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << "Try find spans when one element" << std::endl;
		Span	sp(10);
		sp.addNumber(10);
		try {
			std::cout << "Call shortestSpan : ";
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "Call longestSpan : ";
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << "Another addNumber func" << std::endl;
		Span	sp(5);
		int		toAdd[5] = {1, 2, 3, 4,5};

		sp.addNumber(toAdd, toAdd + 5);
		sp.print();
		try {
			std::cout << std::endl << "Try to add when span is full" << std::endl;
			sp.addNumber(10);
		}
		catch (std::exception& e) {
			std::cout << "catch! " << e.what() << std::endl;
		}
	}
	return 0;
}
