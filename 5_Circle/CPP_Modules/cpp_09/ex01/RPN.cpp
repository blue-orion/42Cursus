/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 23:07:02 by takwak            #+#    #+#             */
/*   Updated: 2025/05/28 23:07:02 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <string>

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN& other) : _st(other._st) {}
const RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		_st = other._st;
	}
	return *this;
}

int	RPN::evalExpression(char* expr) {
	std::stringstream	ss(expr);
	std::string			token;

	while (ss >> token) {
		if (token.size() >= 2) {
			throw std::logic_error("Error");
		}
		if (std::isdigit(token[0])) {
			_st.push(token[0] - '0');
			continue ;
		}
		if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
			_st.push(token[0]);
			calculate();
			continue ;
		}
		throw std::logic_error("Error");
	}
	if (_st.size() < 1 || _st.size() >= 2) {
		throw std::logic_error("Error");
	}
	return _st.top();
}

void	RPN::calculate() {
	char	expr = _st.top();
	_st.pop();
	int	b = _st.top();
	_st.pop();
	int	a = _st.top();
	_st.pop();

	// std::cout << "expr: " << a << expr << b << std::endl;
	if (expr == '+') {
		_st.push(a + b);
	}
	if (expr == '-') {
		_st.push(a - b);
	}
	if (expr == '*') {
		_st.push(a * b);
	}
	if (expr == '/') {
		if (b == 0) {
			throw std::runtime_error("Error: Division by zero");
		}
		_st.push(a / b);
	}
}
