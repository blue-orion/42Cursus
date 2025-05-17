/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 02:43:06 by takwak            #+#    #+#             */
/*   Updated: 2025/05/17 15:59:35 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "Test with MutantStack" << std::endl;
	MutantStack<int>	mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "mstack top = " << mstack.top() << std::endl;
	std::cout << std::endl;
	mstack.pop();
	std::cout << "mstack size = " << mstack.size() << std::endl;
	std::cout << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::const_iterator ite = mstack.cend();
	++it;
	--it;
	std::cout << "===== mstack elements =====" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);

	std::cout << std::endl << "Test with std::list" << std::endl;
	std::list<int>	lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "list back = " <<lst.back() << std::endl;
	std::cout << std::endl;
	lst.pop_back();
	std::cout << "list size = " << lst.size() << std::endl;
	std::cout << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	//[...]
	lst.push_back(0);
	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();
	++lit;
	--lit;
	std::cout << "===== list elements =====" << std::endl;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
	std::cout << std::endl;
	return 0;
}
