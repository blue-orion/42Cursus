#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>

void	mergeInsertSort(std::vector<int> data);
void	sortMainChain(std::vector<int> mainChain, std::vector< std::pair<int, int> > pairs);
void	binaryInsert(std::vector<int> mainChain, int element, int start, int last);

int	main(int ac, char **av) {
	std::vector<int>	data;

	for (int i = 0; av[i]; i++) {
		data.push_back(std::atoi(av[i]));
	}

	std::cout << "Before: ";
	for (std::vector<int>::iterator it = data.begin(); it != data.end() - 1; ++it) {
		std::cout << *it << " ";
	}
	std::cout << *(data.end() - 1) << std::endl;

	mergeInsertSort(data);
}

void	mergeInsertSort(std::vector<int> data) {
	std::vector<std::pair<int, int> >	temp;

	for (std::vector<int>::iterator it = data.begin(); it != data.end(); it += 2) {
		if (*it > *(it + 1)) {
			temp.push_back(std::pair<int, int>(*it, *(it + 1)));
		}
		else {
			temp.push_back(std::pair<int, int>(*(it + 1), *it));
		}
		data.erase(it);
		data.erase(it + 1);
	}

	sortMainChain(data, temp);

	std::vector<int>	t;
	t[0] = 1;
	for (int k = 1; t[k] <= temp.size(); t[k] = std::pow(2, k) - t[k - 1]) {
		std::cout << "k = " << k << ", jacobstal = " << t[k] << std::endl;
		for (int i = t[k]; i > t[k - 1]; --i) {
			data.push_back(temp[t[k - 1] + 1].first);
			binaryInsert(data, temp[i].second, 0, data.size());
			
		}
	}
}

void	sortMainChain(std::vector<int> mainChain, std::vector< std::pair<int, int> > pairs) {
	std::vector< std::pair<int, int> >	result;
	std::vector<int>	temp;

	for (std::vector< std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		temp.push_back(it->first);
	}
	mergeInsertSort(temp);
	for (std::vector<int>::iterator it = temp.begin(); it != temp.end(); ++it) {
		for (std::vector< std::pair<int, int> >::iterator iter = pairs.begin(); iter != pairs.end(); ++iter) {
			if (*it == iter->first) {
				if (it == temp.begin()) {
					mainChain.push_back(iter->second);
					mainChain.push_back(iter->first);
				}
				else
					result.push_back(*iter);
				pairs.erase(iter);
			}
		}
	}
	pairs = result;
}

void	binaryInsert(std::vector<int> mainChain, int element, int start, int last) {
	int	middle = (start + last) / 2;

	if (middle == start) {
		if (element < mainChain[middle]) {
			mainChain.insert(mainChain.begin() + middle - 1, element);
		}
		else {
			mainChain.insert(mainChain.begin() + middle + 1, element);
		}
		return ;
	}
	if (element < mainChain[middle]) {
		binaryInsert(mainChain, element, start, middle - 1);
	}

	if (element > mainChain[middle]) {
		binaryInsert(mainChain, element, middle + 1, last);
	}
}
