/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:05:45 by takwak            #+#    #+#             */
/*   Updated: 2025/05/17 01:32:58 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <vector>

class Span {
private:
	std::vector<int>	_data;
	unsigned int		_maxSize;

public:
	Span();
	~Span();
	Span(const Span& other);
	Span&	operator=(const Span& other);

	Span(unsigned int N);

	void	addNumber(int value);
	void	addNumber(int count, int value);

	template <typename Iterator>
	void	addNumber(Iterator start, Iterator end) {
		for (Iterator it = start; it < end; it++) {
			if (_data.size() >= _maxSize) {
				throw std::out_of_range("Out of range exception");
			}
			_data.push_back(*it);
		}
	}

	int		shortestSpan() const;
	int		longestSpan() const;

	void	print() const;
};
