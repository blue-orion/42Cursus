#include <limits>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "PmergeMe.hpp"

bool	check_alpha(char *s);
bool	validate_input(int ac, char **av);

int	main(int ac, char **av) {
	if (ac < 2) {
		return 1;
	}
	if (validate_input(ac, av)) {
		std::cerr << "Error: invalid input" << std::endl;
		return 1;
	}
	std::vector<int>	vec(ac);
	for (int i = 1; i < ac; i++) {
		vec.push_back(std::atoi(av[i]));
	}
	std::cout << "Before: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		if (it != vec.end() - 1)
			std::cout << *it << " ";
		else 
			std::cout << *it << std::endl;
	}

	PmergeMe	data(vec);
	data.mergeInsertSort();

	std::cout << "After: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		if (it != vec.end() - 1)
			std::cout << *it << " ";
		else 
			std::cout << *it << std::endl;
	}
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
	for (int i = 0; i < std::strlen(s); ++i) {
		if (!std::isdigit(s[i])) {
			return true;
		}
	}
	return false;
}
