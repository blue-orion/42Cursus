/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:47:31 by takwak            #+#    #+#             */
/*   Updated: 2025/05/18 03:51:28 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>
#include <fstream>
#include <utility>

BitcoinExchange::BitcoinExchange() : _data() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {}
BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		_data = other._data;
	}
	return *this;
}

void	BitcoinExchange::saveDataFromFile(char *filename) {
	std::ifstream	ifs(filename);
	std::string		line;
	std::string		key;
	std::string		value;

	while (!ifs.eof()) {
		std::getline(ifs, line);
		if (ifs.fail()) {
			throw std::exception();
		}
		std::size_t splitPoint = line.find("|", 0);
		key = line.substr(0, splitPoint - 1);
		value = line.substr(splitPoint + 2);
		this->_data.insert(std::pair <std::string, int>(key, std::stoi(value)));
	}
}

void	BitcoinExchange::printData() {}
