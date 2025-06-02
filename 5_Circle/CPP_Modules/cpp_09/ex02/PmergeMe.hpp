#pragma	once

#include <vector>

class PmergeMe {
private:
	std::vector<int>					_mainChain;
	std::vector< std::pair<int, int> >	_pairs;

public:
	typedef std::vector<int>					mainChain;
	typedef std::vector< std::pair<int, int> >	pairs;

	void	mergeInsertSort(std::vector<int>& data);
	void	generalize();
	void	insertElements();
};
