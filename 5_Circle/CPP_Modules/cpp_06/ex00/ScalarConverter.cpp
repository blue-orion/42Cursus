/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:10:05 by takwak            #+#    #+#             */
/*   Updated: 2025/05/15 17:55:19 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cmath>

void	ScalarConverter::convert(char *input) {
	std::string	inputStr = input;
	char	c;
	int		i;
	float	f;
	double	d;

	int		type = detectType(input);
	switch (type) {
		case PSEUDO:
			c = PSEUDO;
			i = PSEUDO;
			if (!strncmp(input, "nan", 3)) {
				f = nanf("");
				d = nan("");
			}
			if (!strncmp(input, "+inf", 4)) {
				f = INFINITY;
				d = INFINITY;
			}
			if (!strncmp(input, "-inf", 4)) {
				f = -INFINITY;
				d = -INFINITY;
			}
			if (!strncmp(input, "inf", 3)) {
				f = INFINITY;
				d = INFINITY;
			}
			break ;

		case CHAR:
			c = *input;
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break ;

		case INT:
			i = atoi(input);
			c = castToChar(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break ;

		case FLOAT:
			f = strtof(input, NULL);
			c = castToChar(f);
			i = castToInt(f);
			d = static_cast<double>(f);
			break ;

		case DOUBLE:
			d = strtod(input, NULL);
			c = castToChar(d);
			i = castToInt(d);
			f = castToFloat(d);
			break ;

		default:
			std::cout << "Invalid Input" << std::endl;
			return ;
	}

	printResult(c, i, f, d);
}

void	printResult(char c, int i, float f, double d) {
	std::cout << "char   : ";
	if (c == PSEUDO || (c == 0 && c != static_cast<int>(d)))
		std::cout << "Impossible" << std::endl;
	else if (isprint(c))
		std::cout << "\'" << c << "\'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int    : ";
	if (i == PSEUDO || (i == 0 && i != static_cast<int>(d)))
		std::cout << "Impossible" << std::endl;
	else
		std::cout << i << std::endl;

	std::cout << "float  : ";
	std::cout << std::fixed << std::setprecision(3) << f << "f" << std::endl;

	std::cout << "double : ";
	std::cout << std::fixed << std::setprecision(3) <<d << std::endl;
}
