#pragma	once

#include <vector>
#include <iostream>
#include <deque>

class PmergeMe {
private:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	const PmergeMe& operator=(const PmergeMe& other);

	int		_size;
	int		_last;
	bool	_lastExist;
	std::vector<int>					_mainChainVec;
	std::vector< std::pair<int, int> >	_pairsVec;

	std::deque<int>						_mainChainDeque;
	std::deque< std::pair<int, int> >	_pairsDeque;

public:
	PmergeMe(std::vector<int>& data);
	PmergeMe(std::deque<int>& data);
	~PmergeMe();

	typedef std::vector<int>					mainChainVec;
	typedef std::vector< std::pair<int, int> >	pairsVec;
	typedef std::deque<int>						mainChainDeque;
	typedef std::deque< std::pair<int, int> >	pairsDeque;

	static void	mergeInsertSortByVector(std::vector<int>& data);
	void		generalizeVector();
	void		insertElementsVector();
	void		binaryInsertVector(int target, int start, int end);

	static void	mergeInsertSortByDeque(std::deque<int>& data);
	void		generalizeDeque();
	void		insertElementsDeque();
	void		binaryInsertDeque(int target, int start, int end);
};

template <typename T>
bool	isSorted(T vec) {
	for (typename T::iterator it = vec.begin(); it != vec.end() - 1; ++it) {
		typename T::iterator	next = it + 1;
		if (*it > *next) {
			return false;
		}
	}
	return true;
}

template <typename iter>
bool	isSorted(iter start, iter end) {
	for (iter it = start; it != end - 1; ++it) {
		iter	next = it + 1;
		std::cout << *it << ", " << *next << std::endl;
		if (*it >= *next) {
			return false;
		}
	}
	return true;
}

template <typename T>
void	printElements(T container) {
	for (std::size_t i = 0; i < container.size(); i++) {
		if (i == 4 && container.size() > 5) {
			std::cout << "[...]" << std::endl;
			break ;
		}
		if (i != container.size() - 1)
			std::cout << container[i] << " ";
		else 
			std::cout << container[i] << std::endl;
	}
}
