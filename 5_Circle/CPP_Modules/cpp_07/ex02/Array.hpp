#pragma once

#include <stdexcept>
#include <cstdlib>

template <typename T>
class Array {
private:
	T	*arr;
	int	arr_size;

public:
	Array() : arr(NULL), arr_size(0) {}

	~Array() {
		delete[] arr;
	}

	Array(const Array& other) : arr(new T[other.arr_size]), arr_size(other.arr_size) {
		for (int i = 0; i < other.size(); i++) {
			arr[i] = other[i];
		}
	}

	Array&	operator=(const Array& other) {
		if (this == &other)
			return *this;
		delete[] arr;

		arr = new T[other.size()];
		for (int i = 0; i < other.arr_size; i++) {
			arr[i] = other[i];
		}
		return *this;
	}

	Array(int size) : arr(new T[size]), arr_size(size) {}

	T&	operator[](int index) {
		if (index < 0 || index >= arr_size)
			throw std::out_of_range("Out of range error");
		return arr[index];
	}

	const T&	operator[](int index) const{
		if (index < 0 || index >= arr_size)
			throw std::out_of_range("Out of range error");
		return arr[index];
	}

	int	size() const {
		return arr_size;
	}
};
