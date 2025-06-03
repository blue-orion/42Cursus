#include <limits>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "PmergeMe.hpp"

bool	check_alpha(char *s);
bool	validate_input(int ac, char **av);
std::string	isSorted(std::vector<int> vec);

int	main(int ac, char **av) {
	if (ac < 2) {
		return 1;
	}
	if (validate_input(ac, av)) {
		std::cerr << "Error: invalid input" << std::endl;
		return 1;
	}

	clock_t	vectorTime;
	clock_t	dequeTime;

	std::vector<int>	vec;
	std::deque<int>		deque;
	std::vector<int>	stdsort;
	for (int i = 1; i < ac; i++) {
		vec.push_back(std::atoi(av[i]));
		deque.push_back(std::atoi(av[i]));
		stdsort.push_back(std::atoi(av[i]));
	}
	std::cout << "Before: ";
	for (std::size_t i = 0; i < vec.size(); i++) {
		if (i == 4 && vec.size() > 5) {
			std::cout << "[...]" << std::endl;
			break ;
		}
		if (i != vec.size() - 1)
			std::cout << vec[i] << " ";
		else 
			std::cout << vec[i] << std::endl;
	}

	vectorTime = clock();
	PmergeMe::mergeInsertSortByVector(vec);
	vectorTime = clock() - vectorTime;

	std::cout << "After: ";
	for (std::size_t i = 0; i < 5; i++) {
		if (i == 4 && vec.size() > 5) {
			std::cout << "[...]" << std::endl;
			break ;
		}
		if (i != 4)
			std::cout << vec[i] << " ";
		else 
			std::cout << vec[i] << std::endl;
	}

	std::cout << isSorted< std::vector<int> >(vec) << std::endl;

	std::cout << "Before: ";
	for (std::size_t i = 0; i < deque.size(); i++) {
		if (i == 4 && deque.size() > 5) {
			std::cout << "[...]" << std::endl;
			break ;
		}
		if (i != 4)
			std::cout << deque[i] << " ";
		else 
			std::cout << deque[i] << std::endl;
	}

	dequeTime = clock();
	PmergeMe::mergeInsertSortByDeque(deque);
	dequeTime = clock() - dequeTime;

	std::cout << "After: ";
	for (std::size_t i = 0; i < deque.size(); i++) {
		if (i == 4 && deque.size() > 5) {
			std::cout << "[...]" << std::endl;
			break ;
		}
		if (i != 4)
			std::cout << deque[i] << " ";
		else 
			std::cout << deque[i] << std::endl;
	}

	std::cout << isSorted< std::deque<int> >(deque) << std::endl;

	std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << static_cast<float>(vectorTime) / CLOCKS_PER_SEC * 1000 << "us" <<  std::endl;
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << static_cast<float>(dequeTime) / CLOCKS_PER_SEC * 1000 << "us" << std::endl;

	// dequeTime = clock();
	// std::sort(stdsort.begin(), stdsort.end());
	// dequeTime = clock() - dequeTime;
	// std::cout << "Time to process a range of " << ac - 1 << " elements with std::sort(std::vector) : " << static_cast<float>(dequeTime) / CLOCKS_PER_SEC * 1000 << "us" << std::endl;
	return 0;
}

bool	validate_input(int ac, char **av) {
	for (int i = 1; i < ac; i++) {
		if (check_alpha(av[i])) {
			return true;
		}

		long	element = std::atoi(av[i]);
		if (element < 0 || element > std::numeric_limits<int>::max()) {
			return true;
		}

		for (int j = 1; j < i; j++) {
			if (av[i] == av[j]) {
				return true;
			}
		}
	}
	return false;
}

bool	check_alpha(char *s) {
	for (std::size_t i = 0; i < std::strlen(s); ++i) {
		if (!std::isdigit(s[i])) {
			return true;
		}
	}
	return false;
}
