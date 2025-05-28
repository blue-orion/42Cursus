/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:47:31 by takwak            #+#    #+#             */
/*   Updated: 2025/05/28 15:06:08 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() : _data() {
	std::ifstream	ifs("data.csv");
	std::string		line;
	std::string		key;
	std::string		value;

	while (std::getline(ifs, line)) {
		std::size_t splitPoint = line.find(",");
		key = line.substr(0, splitPoint - 1);
		value = line.substr(splitPoint + 2);
		_data[key] = std::atoi(value.c_str());
	}
	ifs.close();
}

BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data) {}
BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		_data = other._data;
	}
	return *this;
}

void	BitcoinExchange::makeResults(char *input) {
	std::ifstream	ifs(input);
	std::stringstream	ss;
	std::string		line;
	std::string		date;
	int				value;
	int				exchange;

	while (std::getline(ifs, line)) {
		std::size_t	splitPoint = line.find("|");
		if (splitPoint == std::string::npos) {
			//예외
		}
		line[splitPoint] = ' ';
		ss << line;

		ss >> date >> value;
		exchange = findProperValue(date);
		std::cout << date << value << value * exchange << std::endl;
	}
}

int	BitcoinExchange::findProperValue(std::string date) {
	std::map<std::string, int>::iterator	it;
	std::pair<std::string, int>	matched;

	for (it = _data.begin(); it != _data.end(); ++it) {
		matched = *it;
		if (matched.first >= date)
			break ;
	}
	if (matched.first != date) {
	}
	return matched.second;
}

void	BitcoinExchange::printData() {
	BitcoinExchange::iterator	it;
	for (it = _data.begin(); it != _data.end(); it++) {
		std::cout << "Day : " << it->first << " | Value : " << it->second << std::endl;
	}
}
