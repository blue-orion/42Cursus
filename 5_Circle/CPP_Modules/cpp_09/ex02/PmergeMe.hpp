#pragma	once

#include <vector>

class PmergeMe {
private:
	std::vector<int>	_elements;

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe& other);
	const PmergeMe& operator=(const PmergeMe& other);

	const std::vector<int>&	getElements() const;
	void					addElement(int element);
	void					setElements(std::vector<int> vectorData);

	void					addArguments(char **av);

	void	makePairs();
};
