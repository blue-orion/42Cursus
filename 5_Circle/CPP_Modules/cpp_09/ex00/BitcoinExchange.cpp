/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 21:17:43 by takwak            #+#    #+#             */
/*   Updated: 2025/05/28 22:52:16 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <climits>
#include <stdexcept>
#include <sstream>
#include <iostream>

BitcoinExchange::BitcoinExchange() {
	std::ifstream	ifs("data.csv");
	std::string		line;

	if (!ifs.is_open())
		throw std::runtime_error("Error: No exist database file");

	std::getline(ifs, line);
	if (line != "date,exchange_rate") {
		throw std::runtime_error("Error: Invalid database header");
	}

	while (std::getline(ifs, line)) {
		validateCsvLine(line);

		std::size_t	comma = line.find(",");
		std::string	key = line.substr(0, comma);
		std::string	value = line.substr(comma + 1);

		_csvData[key] = std::atof(value.c_str());
	}
}

void	BitcoinExchange::validateCsvLine(std::string line) {
	std::size_t	comma = line.find(",");

	if (line.find(",", comma + 1) != std::string::npos) {
		throw InvalidException("Error: Invalid line: " + line);
	}

	std::string	key = line.substr(0, comma);
	std::string	value = line.substr(comma + 1);

	validateDate(key);
	validateValue(value);
}

void	BitcoinExchange::makeResults(char *input) {
	std::ifstream	ifs(input);
	std::string		line;

	if (!ifs.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::getline(ifs, line);
	if (line != "date | value") {
		throw InvalidException("Error: Invalid input file header");
	}

	while (std::getline(ifs, line)) {
		try {
			validateInputLine(line);
		}
		catch (InvalidException& ex) {
			std::cout << ex.what() << std::endl;
			continue ;
		}

		std::size_t	comma = line.find("|");
		std::string	key = line.substr(0, comma - 1);
		std::string	value = line.substr(comma + 2);

		double	result = std::atof(value.c_str()) * findExchangeRate(key);
		std::cout << key << " => " << value << " => " << result << std::endl;
	}
}

double	BitcoinExchange::findExchangeRate(std::string date) {
	std::map<std::string, double>::iterator	it;
	std::pair<std::string, double>	pair;

	for (it = _csvData.begin(); it != _csvData.end(); ++it) {
		if (it->first >= date) {
			break ;
		}
		pair = *it;
	}
	if (it->first > date) {
		return pair.second;
	}
	return it->second;
}

void	BitcoinExchange::validateInputLine(std::string line) {
	std::size_t	separator= line.find("|");

	if (line.find("|", separator + 1) != std::string::npos) {
		throw InvalidException("Error: Invalid line: " + line);
	}

	std::string	key = line.substr(0, separator - 1);
	std::string	value = line.substr(separator + 2);

	validateDate(key);
	validateValue(value);
}

void	BitcoinExchange::validateDate(std::string date) {
	std::stringstream	ss(date);
	std::string	token;
	int			year;
	int			month;
	int			day;
	int			cnt = 0;

	for (std::string::iterator it = date.begin(); it != date.end(); ++it) {
		if (*it == '-')
			cnt++;
	}
	if (cnt != 2) {
		throw InvalidException("Error: bad input => " + date);
	}

	std::getline(ss, token, '-');
	year = std::atoi(token.c_str());
	if (year > 2025) {
		throw InvalidException("Error: bad input => " + date);
	}

	std::getline(ss, token, '-');
	month = std::atoi(token.c_str());
	if (month > 12) {
		throw InvalidException("Error: bad input => " + date);
	}

	std::getline(ss, token, '-');
	day = std::atoi(token.c_str());
	if (month == 1 || month == 3 || month == 5 || month == 7
		|| month == 8 || month == 10 || month == 12)
	{
		if (day > 31) {
			std::cout << day << std::endl;
			throw InvalidException("Error: bad input => " + date);
		}
	}
	if (month == 2 && day > 28) {
		throw InvalidException("Error: bad input => " + date);
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30) {
			throw InvalidException("Error: bad input => " + date);
		}
	}
}

void	BitcoinExchange::validateValue(std::string value) {
	std::stringstream	ss(value);
	double				number;
	std::size_t			dot;

	dot = value.find(".");
	if (value.find(".", dot + 1) != std::string::npos) {
		throw InvalidException("Error: not a invalid number");
	}
	ss >> number;
	if (number < 0) {
		throw InvalidException("Error: not a positive number");
	}
	if (number > 1000) {
		throw InvalidException("Error: too large a number");
	}
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _csvData(other._csvData) {}

const BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		_csvData = other._csvData;
	}
	return *this;
}

BitcoinExchange::InvalidException::InvalidException(const std::string& what_arg) : _what_arg(what_arg) {}
BitcoinExchange::InvalidException::InvalidException(const InvalidException& other) : _what_arg(other._what_arg) {}
BitcoinExchange::InvalidException::~InvalidException() throw() {}

const char* BitcoinExchange::InvalidException::what() const throw() {
	return _what_arg.c_str();
}
