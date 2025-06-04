#include "PmergeMe.hpp"
#include <vector>
#include <cstdlib>
#include <cmath>

int	jacobstalNum(int k) {
	return (pow(2, k + 1) + pow(-1, k)) / 3;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int>& data) {
	_size = data.size();
	_lastExist = false;
	for (mainChainVec::iterator it = data.begin(); it != data.end(); it += 2) {
		std::pair<int, int>	pair;
		
		if (it + 1 == data.end()) {
			_last = *it;
			_lastExist = true;
			break ;
		}
		if (*it >= *(it + 1)) {
			pair.first = *it;
			pair.second = *(it + 1);
		}
		else {
			pair.first = *(it + 1);
			pair.second = *it;
		}
		_mainChainVec.push_back(pair.first);
		_pairsVec.push_back(pair);
	}
}

PmergeMe::PmergeMe(std::deque<int>& data) {
	_size = data.size();
	_lastExist = false;
	for (mainChainDeque::iterator it = data.begin(); it != data.end(); it += 2) {
		std::pair<int, int>	pair;
		
		if (it + 1 == data.end()) {
			_last = *it;
			_lastExist = true;
			break ;
		}
		if (*it >= *(it + 1)) {
			pair.first = *it;
			pair.second = *(it + 1);
		}
		else {
			pair.first = *(it + 1);
			pair.second = *it;
		}
		_mainChainDeque.push_back(pair.first);
		_pairsDeque.push_back(pair);
	}
}

void	PmergeMe::mergeInsertSortByVector(std::vector<int>& data) {
	PmergeMe	vec(data);

	if (data.size() > 5) {
		vec.mergeInsertSortByVector(vec._mainChainVec);
	}
	if (data.size() <= 5) {
		if (vec._pairsVec.size() > 1 && vec._mainChainVec[0] > vec._mainChainVec[1]) {
			std::swap(vec._mainChainVec[0], vec._mainChainVec[1]);
		}
	}

	vec.generalizeVector();

	vec.insertElementsVector();

	data = vec._mainChainVec;
}

void	PmergeMe::generalizeVector() {
	pairsVec	newpairsVec;

	for (mainChainVec::iterator it = _mainChainVec.begin(); it != _mainChainVec.end(); ++it) {
		for (pairsVec::iterator pit = _pairsVec.begin(); pit != _pairsVec.end(); ++pit) {
			if (*it == pit->first) {
				newpairsVec.push_back(*pit);
				pit = _pairsVec.erase(pit);
				break ;
			}
		}
	}
	_pairsVec = newpairsVec;
}

void	PmergeMe::insertElementsVector() {
	int	k;

	for (k = 1; _size >= 2 * jacobstalNum(k) - 1; ++k) {
		int	endPoint = 2 * jacobstalNum(k - 1) + (jacobstalNum(k) - jacobstalNum(k - 1) - 1);

		if (k == 1) {
			binaryInsertVector(_pairsVec[0].second, 0, endPoint);
			continue ;
		}

		for (int i = jacobstalNum(k) - 1; i > jacobstalNum(k - 1) - 1; --i) {
			if (_lastExist == true && _size == 2 * jacobstalNum(k) - 1) {
				binaryInsertVector(_last, 0, endPoint);
				_lastExist = false;
				continue ;
			}
			binaryInsertVector(_pairsVec[i].second, 0, endPoint);
		}
	}

	if (_size != 2 * jacobstalNum(k) - 1) {
		for (int i = (_size - 1) / 2; i > jacobstalNum(k - 1) - 1; --i) {
			if (_lastExist == true && _size % 2 == 1) {
				binaryInsertVector(_last, 0, _mainChainVec.size());
				_lastExist = false;
				continue ;
			}
			binaryInsertVector(_pairsVec[i].second, 0, _mainChainVec.size());
		}
	}
}

void	PmergeMe::binaryInsertVector(int target, int start, int end) {
	int	middle = (start + end) / 2;
	
	if (start == end) {
		middle--;
	}

	if (end - start <= 1) {
		if (target <= _mainChainVec[middle]) {
			_mainChainVec.insert(_mainChainVec.begin() + middle, target);
		}
		if (target > _mainChainVec[middle]) {
			if (static_cast<size_t>(middle + 1) > _mainChainVec.size()) {
				_mainChainVec.push_back(target);
				return ;
			}
			_mainChainVec.insert(_mainChainVec.begin() + middle + 1, target);
		}
		return ;
	}

	if (target <= _mainChainVec[middle]) {
		binaryInsertVector(target, start, middle);
	}
	if (target > _mainChainVec[middle]) {
		binaryInsertVector(target, middle + 1, end);
	}
}

void	PmergeMe::mergeInsertSortByDeque(std::deque<int>& data) {
	PmergeMe	deque(data);

	if (data.size() > 5) {
		deque.mergeInsertSortByDeque(deque._mainChainDeque);
	}
	if (data.size() <= 5) {
		if (deque._pairsDeque.size() > 1 && deque._mainChainDeque[0] > deque._mainChainDeque[1]) {
			std::swap(deque._mainChainDeque[0], deque._mainChainDeque[1]);
		}
	}

	deque.generalizeDeque();

	deque.insertElementsDeque();

	data = deque._mainChainDeque;
}

void	PmergeMe::generalizeDeque() {
	pairsDeque	newpairsDeque;

	for (mainChainDeque::iterator it = _mainChainDeque.begin(); it != _mainChainDeque.end(); ++it) {
		for (pairsDeque::iterator pit = _pairsDeque.begin(); pit != _pairsDeque.end(); ++pit) {
			if (*it == pit->first) {
				newpairsDeque.push_back(*pit);
				pit = _pairsDeque.erase(pit);
				break ;
			}
		}
	}
	_pairsDeque = newpairsDeque;
}

void	PmergeMe::insertElementsDeque() {
	int	k;

	for (k = 1; _size >= 2 * jacobstalNum(k) - 1; ++k) {
		int	endPoint = 2 * jacobstalNum(k - 1) + (jacobstalNum(k) - jacobstalNum(k - 1) - 1);

		if (k == 1) {
			binaryInsertDeque(_pairsDeque[0].second, 0, endPoint);
			continue ;
		}

		for (int i = jacobstalNum(k) - 1; i > jacobstalNum(k - 1) - 1; --i) {
			if (_lastExist == true && _size == 2 * jacobstalNum(k) - 1) {
				binaryInsertDeque(_last, 0, endPoint);
				_lastExist = false;
				continue ;
			}
			binaryInsertDeque(_pairsDeque[i].second, 0, endPoint);
		}
	}

	if (_size != 2 * jacobstalNum(k) - 1) {
		for (int i = (_size - 1) / 2; i > jacobstalNum(k - 1) - 1; --i) {
			if (_lastExist == true && _size % 2 == 1) {
				binaryInsertDeque(_last, 0, _mainChainDeque.size());
				_lastExist = false;
				continue ;
			}
			binaryInsertDeque(_pairsDeque[i].second, 0, _mainChainDeque.size());
		}
	}
}

void	PmergeMe::binaryInsertDeque(int target, int start, int end) {
	int	middle = (start + end) / 2;
	
	if (start == end) {
		middle--;
	}

	if (end - start <= 1) {
		if (target <= _mainChainDeque[middle]) {
			_mainChainDeque.insert(_mainChainDeque.begin() + middle, target);
		}
		if (target > _mainChainDeque[middle]) {
			if (static_cast<size_t>(middle + 1) > _mainChainDeque.size()) {
				_mainChainDeque.push_back(target);
				return ;
			}
			_mainChainDeque.insert(_mainChainDeque.begin() + middle + 1, target);
		}
		return ;
	}

	if (target <= _mainChainDeque[middle]) {
		binaryInsertDeque(target, start, middle);
	}
	if (target > _mainChainDeque[middle]) {
		binaryInsertDeque(target, middle + 1, end);
	}
}
