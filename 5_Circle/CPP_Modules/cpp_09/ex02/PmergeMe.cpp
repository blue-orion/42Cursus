#include "PmergeMe.hpp"
#include <vector>
#include <cstdlib>

void	PmergeMe::mergeInsertSort(std::vector<int>& data) {

	for (mainChain::iterator it = data.begin(); it != data.end(); it += 2) {
		std::pair<int, int>	pair;
		
		if (*it > *(it + 1)) {
			pair.first = *it;
			pair.second = *(it + 1);
		}
		else {
			pair.first = *(it + 1);
			pair.second = *it;
		}
		_mainChain.push_back(pair.first);
		_pairs.push_back(pair);
	}

	mergeInsertSort(_mainChain);

	generalize();

	insertElements();

	data = _mainChain;
}

void	PmergeMe::generalize() {
	pairs	newPairs;

	for (mainChain::iterator it = _mainChain.begin(); it != _mainChain.end(); ++it) {
		for (pairs::iterator pit = _pairs.begin(); pit != _pairs.end(); ++pit) {
			if (*it == pit->first) {
				newPairs.push_back(*pit);
				pit = _pairs.erase(pit);
				break ;
			}
		}
	}
	_pairs = newPairs;
}

void	PmergeMe::insertElements() {

}
