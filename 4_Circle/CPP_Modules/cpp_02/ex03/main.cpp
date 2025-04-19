/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 23:32:42 by takwak            #+#    #+#             */
/*   Updated: 2025/04/20 01:52:21 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main( void ) {
	Point	A(2, 2);
	Point	B(5, 2);
	Point	C(5, 10);

	std::cout << "A(2, 2) B(5, 2) C(5, 10)" << std::endl;

	std::cout << std::endl << "On edge point (4, 2)" << std::endl;
	if (bsp(A, B, C, Point(4, 2)))
		std::cout << "In triangle" << std::endl;
	else
		std::cout << "Out triangle" << std::endl;

	std::cout << std::endl << "In triangle point (4, 6)" << std::endl;
	if (bsp(A, B, C, Point(4, 6)))
		std::cout << "In triangle" << std::endl;
	else
		std::cout << "Out triangle" << std::endl;

	std::cout << std::endl << "In triangle point (3.5, 5.5)" << std::endl;
	if (bsp(A, B, C, Point(3.5f, 5.5f)))
		std::cout << "In triangle" << std::endl;
	else
		std::cout << "Out triangle" << std::endl;

	std::cout << std::endl << "Out triangle point (10, 10)" << std::endl;
	if (bsp(A, B, C, Point(10, 10)))
		std::cout << "In triangle" << std::endl;
	else
		std::cout << "Out triangle" << std::endl;

	std::cout << std::endl << "Vertex point (5, 10)" << std::endl;
	if (bsp(A, B, C, Point(5, 10)))
		std::cout << "In triangle" << std::endl;
	else
		std::cout << "Out triangle" << std::endl;
	return 0;
}
