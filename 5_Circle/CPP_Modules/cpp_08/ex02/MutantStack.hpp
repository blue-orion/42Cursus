/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 01:22:13 by takwak            #+#    #+#             */
/*   Updated: 2025/05/17 02:48:59 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

#include <iostream>
#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
private:
	;

public:
	typedef typename Container::iterator iterator;
	/*bool		empty() const;*/
	/*std::size_t	size() const;*/
	/*T			top() const;*/
	/*void		push();*/
	/*void		emplace();*/
	/*void		pop();*/
	/*void		swap();*/

	iterator	begin() {return this->c.begin();}
	iterator	end() {return this->c.end();}
	iterator	begin() const {return this->c.begin();}
	iterator	end() const {return this->c.end();}

	void	print() {
		for (iterator it = this->c.end() - 1; it >= this->c.begin(); it--) {
			std::cout << *it << " " << std::endl;
		}
	}
};
