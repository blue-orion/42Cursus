/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:56:29 by takwak            #+#    #+#             */
/*   Updated: 2025/05/16 19:49:36 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <vector>
#include "easyfind.hpp"

int	main(void) {
	int	a[5] = {10, 20, 30, 40, 50};
	std::vector<int> myvec(a, a+5);

	int	*p = std::find(a, a + 5, 50);
	if (p != a + 5)
		std::cout << "found!" << *p << std::endl;
	else
		std::cout << "Can't found!" << std::endl;

	std::vector<int>::iterator	i = easyfind(myvec, 50);
	if (i != myvec.end())
		std::cout << "found!" << *i << std::endl;
	else
		std::cout << "Can't found!" << std::endl;
}
