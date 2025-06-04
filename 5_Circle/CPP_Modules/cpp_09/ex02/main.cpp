#include "PmergeMe.hpp"
#include <limits>
#include <cstdlib>
#include <cstring>
#include <iostream>

bool	check_alpha(char *s);
bool	validate_input(int ac, char **av);

int	main(int ac, char **av) {
	std::vector<int>	vec;
	clock_t				vectorTime;
	std::deque<int>		deque;
	clock_t				dequeTime;

	if (validate_input(ac, av)) {
		std::cerr << "Error: invalid input" << std::endl;
		return 1;
	}

	for (int i = 1; i < ac; i++) {
		vec.push_back(std::atoi(av[i]));
		deque.push_back(std::atoi(av[i]));
	}

	if (isSorted(vec)) {
		std::cerr << "Error: already sorted" << std::endl;
		return 1;
	}

	std::cout << "Before: ";
	printElements(vec);

	vectorTime = clock();
	PmergeMe::mergeInsertSortByVector(vec);
	vectorTime = clock() - vectorTime;

	std::cout << "After: ";
	printElements(vec);

	// if (isSorted(vec))
	// 	std::cout << "Sorted!" << std::endl;
	// else
	// 	std::cout << "KO" << std::endl;

	std::cout << "Before: ";
	printElements(deque);

	dequeTime = clock();
	PmergeMe::mergeInsertSortByDeque(deque);
	dequeTime = clock() - dequeTime;

	std::cout << "After: ";
	printElements(deque);

	// if (isSorted(vec))
	// 	std::cout << "Sorted!" << std::endl;
	// else
	// 	std::cout << "KO" << std::endl;

	std::cout << "Time to process a range of " << ac - 1
		<< " elements with std::vector : " << static_cast<float>(vectorTime) / CLOCKS_PER_SEC * 1000 << "us" <<  std::endl;
	std::cout << "Time to process a range of " << ac - 1
		<< " elements with std::deque : " << static_cast<float>(dequeTime) / CLOCKS_PER_SEC * 1000 << "us" << std::endl;
	return 0;
}

bool	validate_input(int ac, char **av) {
	if (ac < 2) {
		return true;
	}

	for (int i = 1; i < ac; i++) {
		if (check_alpha(av[i])) {
			return true;
		}

		long	element = std::atoi(av[i]);
		if (element < 0 || element > std::numeric_limits<int>::max()) {
			return true;
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
