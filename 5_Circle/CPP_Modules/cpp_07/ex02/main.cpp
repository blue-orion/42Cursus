#include <iostream>
#include "Array.hpp"
#include <ctime>
#include <cstdlib>


#define MAX_VAL 30
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

	std::cout << std::endl << "Test [] overloading" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
		std::cout << numbers[i] << ", " << mirror[i] << std::endl;
    }

	std::cout << std::endl << "Test shallow copy, if no error, print nothing" << std::endl;
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
		std::cout << std::endl << "Test access -2 index(have to throw exception)" << std::endl;
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "catch!: " << e.what() << '\n';
    }
    try
    {
		std::cout << std::endl << "Test access MAX_VAL index(have to throw exception)" << std::endl;
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "catch!: " << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
