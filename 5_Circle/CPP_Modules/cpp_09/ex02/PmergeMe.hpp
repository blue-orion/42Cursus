#pragma	once

#include <vector>
#include <string>
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
std::string	isSorted(T vec) {
	for (typename T::iterator it = vec.begin(); it != vec.end() - 1; ++it) {
		typename T::iterator	next = it + 1;
		if (*it > *next) {
			return "KO";
		}
	}
	return "Sorted!";
}
