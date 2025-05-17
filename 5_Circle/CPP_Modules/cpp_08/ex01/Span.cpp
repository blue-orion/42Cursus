/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:47:41 by takwak            #+#    #+#             */
/*   Updated: 2025/05/17 15:57:45 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <climits>
#include <algorithm>
#include <cstdlib>
#include <stdexcept>
#include <numeric>

Span::Span() : _maxSize(0) {}

Span::~Span() {}

Span::Span(const Span& other) : _maxSize(other._maxSize) {
	_data = other._data;
}

Span&	Span::operator=(const Span& other) {
	if (this == &other)
		return *this;
	_data = other._data;
	_maxSize = other._maxSize;
	return *this;
}

Span::Span(unsigned int N) : _maxSize(N) {}

void	Span::addNumber(int value) {
	if (_data.size() >= _maxSize)
		throw std::out_of_range("Out of range exception");
	_data.push_back(value);
}

void	Span::addNumber(int count, int value) {
	for (int i = 0; i < count; i++) {
		if (_data.size() >= _maxSize)
			throw std::out_of_range("Out of range exception");
		_data.push_back(value);
	}
}

int	Span::shortestSpan() const {
	if (_data.size() < 2)
		throw std::logic_error("No enough elements");

	std::vector<int> sorted = _data;
	std::sort(sorted.begin(), sorted.end());

	std::vector<int> dist(_data.size());
	std::adjacent_difference(sorted.begin(), sorted.end(), dist.begin());

	int	min_dist = INT_MAX;
	for (size_t i = 1; i < dist.size(); i++) {
		if (dist[i] < min_dist)
			min_dist = dist[i];
	}
	return min_dist;
}

int	Span::longestSpan() const {
	if (_data.size() < 2)
		throw std::logic_error("No enough elements");
	int	max = *std::max_element(_data.begin(), _data.end());
	int	min = *std::min_element(_data.begin(), _data.end());
	return max - min;
}

void	Span::print() const {
	std::cout << "[";
	for (size_t	i = 0; i < _data.size() - 1; i++) {
		std::cout << _data[i] << ", ";
	}
	std::cout << *(_data.end() - 1) << "]" << std::endl;
}
