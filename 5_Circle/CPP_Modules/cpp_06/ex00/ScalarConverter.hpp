/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:42:55 by takwak            #+#    #+#             */
/*   Updated: 2025/05/15 17:47:33 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <limits>
#include <string>
#include <climits>

class ScalarConverter {
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	const ScalarConverter& operator=(const ScalarConverter& other);

public:
	static void	convert(char *input);
};

int		detectType(std::string input);

enum {
	INT = 1,
	FLOAT,
	CHAR,
	DOUBLE,
	PSEUDO,
	ERROR
};

template <typename T>
char	castToChar(T t) {
	if (t >= CHAR_MIN && t <= CHAR_MAX)
		return static_cast<char>(t);
	return 0;
}

template <typename T>
int	castToInt(T t) {
	if (t >= static_cast<double>(INT_MIN) && t <= static_cast<double>(INT_MAX))
		return static_cast<int>(t);
	return 0;
}

template <typename T>
float	castToFloat(T t) {
	return static_cast<float>(t);
	if (t >= std::numeric_limits<float>::min() && t <= std::numeric_limits<float>::max())
		return static_cast<float>(t);
	return 0;
}

void	printResult(char c, int i, float f, double d);
