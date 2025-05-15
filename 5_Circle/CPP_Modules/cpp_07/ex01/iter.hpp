#pragma once

#include <iostream>

template <typename T, typename F>
void	iter(T *arr, int size, F function) {
	for (int i = 0; i < size; i++) {
		function(arr[i]);
	}
}

template <typename T>
void	print(const T& a) {
	std::cout << a << std::endl;
}

