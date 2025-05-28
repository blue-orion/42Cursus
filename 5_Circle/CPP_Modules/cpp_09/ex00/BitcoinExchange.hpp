/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 21:04:16 by takwak            #+#    #+#             */
/*   Updated: 2025/05/28 22:28:56 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <exception>
#include <string>

class	BitcoinExchange {
private:
	std::map<std::string, double>	_csvData;

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	const BitcoinExchange&	operator=(const BitcoinExchange& other);

	void	makeResults(char* input);
	double	findExchangeRate(std::string key);
	void	validateCsvLine(std::string line);
	void	validateInputLine(std::string line);
	void	validateDate(std::string date);
	void	validateValue(std::string value);

	class	InvalidException : public std::exception {
	private:
		std::string	_what_arg;

		InvalidException();
		const InvalidException& operator=(const InvalidException& other);

	public:
		InvalidException(const InvalidException& other);
		InvalidException(const std::string& what_arg);
		~InvalidException() throw();
		virtual	const char* what() const throw();
	};
};
