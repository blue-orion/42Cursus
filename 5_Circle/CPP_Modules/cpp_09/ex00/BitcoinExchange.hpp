/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:47:53 by takwak            #+#    #+#             */
/*   Updated: 2025/05/28 14:52:52 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>

class BitcoinExchange {
private:
	std::map<std::string, int>	_data;

public:
	typedef std::map<std::string, int>::iterator	iterator;
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange&	operator=(const BitcoinExchange& other);

	void	makeResults(char *input);
	int		findProperValue(std::string date);
	void	printData();
};
