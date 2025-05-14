/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detectType.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:00:51 by takwak            #+#    #+#             */
/*   Updated: 2025/05/14 22:00:51 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int		detectType(std::string input) {
	if (input.find("f", input.find(".")))
		return FLOAT;
	if (input.find("."))
		return DOUBLE;
	if (input.length() >= 2)
		return INT;
	if (input.length() == 1)
		return CHAR;
	return 0;
}
