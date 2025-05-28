/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:57:40 by takwak            #+#    #+#             */
/*   Updated: 2025/05/28 22:57:40 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

class	RPN {
private:
	std::stack<int>	_st;

public:
	RPN();
	~RPN();
	RPN(const RPN& other);
	const RPN& operator=(const RPN& other);

	void	calculate();
	int		evalExpression(char* expr);
};
