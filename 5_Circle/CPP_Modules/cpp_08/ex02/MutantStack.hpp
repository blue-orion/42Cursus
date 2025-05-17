/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 01:22:13 by takwak            #+#    #+#             */
/*   Updated: 2025/05/17 20:15:25 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	MutantStack() : std::stack<T, Container>() {}
	~MutantStack() {}
	MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}
	MutantStack&	operator=(const MutantStack& other) {
		if (this != &other) {
			std::stack<T,  Container>::operator=(other);
		}
		return *this;
	}

	typedef typename Container::iterator 		iterator;
	typedef typename Container::const_iterator	const_iterator;

	iterator	begin() {return this->c.begin();}
	iterator	end() {return this->c.end();}
	const_iterator	begin() const {return this->c.begin();}
	const_iterator	end() const {return this->c.end();}
};
