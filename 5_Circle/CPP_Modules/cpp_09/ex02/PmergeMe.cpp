#include "PmergeMe.hpp"
#include <vector>
#include <cstdlib>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) {}
const PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	return *this;
}

const std::vector<int>&	PmergeMe::getElements() const {
	return _elements;
}

void	PmergeMe::addElement(int element) {
	_elements.push_back(element);
}

void	PmergeMe::setElements(std::vector<int> vectorData) {
	_elements = vectorData;
}

void	PmergeMe::addArguments(char **av) {
	for (int i = 0; av[i]; ++i) {
		_elements.push_back(std::atoi(av[i]));
	}
}
