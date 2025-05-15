/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detectType.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:00:51 by takwak            #+#    #+#             */
/*   Updated: 2025/05/15 17:54:46 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>

bool	validate_input(std::string input) {
	int	dot_cnt = 0;
	int	float_cnt = 0;
	for (int i = 1; i < static_cast<int>(input.length()); i++) {
		if (input[i] == '.') {
			dot_cnt++;
			continue ;
		}
		if (input[i] == 'f') {
			float_cnt++;
			continue ;
		}
		if (!std::isdigit(input[i]))
			return 1;
	}
	if (dot_cnt > 1 || float_cnt > 1)
		return 1;
	return 0;
}

int		detectType(std::string input) {
	std::string	input_str = input;

	if (input_str == "nan" || input_str == "nanf"	\
		||	input_str == "+inf" || input_str == "+inff"	\
		||	input_str == "-inf" || input_str == "-inff"	\
		||	input_str == "inf" || input_str == "inff")
		return PSEUDO;

	if (validate_input(input_str))
		return ERROR;

	std::size_t	found = input_str.find(".");
	if (found == std::string::npos && input_str.length() >= 2 && input_str.length() <= 10 && input_str >= "-2147483648" && input_str < "2147483648")
		return INT;
	if (found != std::string::npos && input_str.find("f", found) != std::string::npos)
		return FLOAT;
	if (input_str.length() == 1 && !isdigit(input[0]))
		return CHAR;
	return DOUBLE;
}
