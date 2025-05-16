/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:05:45 by takwak            #+#    #+#             */
/*   Updated: 2025/05/16 21:40:09 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
	int		shortestSpan() const;
	int		longestSpan() const;
};
