/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:48:30 by takwak            #+#    #+#             */
/*   Updated: 2025/05/06 02:28:31 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>


int main()
{
	const Animal* dog = new Dog();
	std::cout << std::endl;
	const Animal* cat = new Cat();
	std::cout << std::endl;
	delete dog;
	std::cout << std::endl;
	delete cat;
	std::cout << std::endl;

	Animal	*arr[10];
	std::cout << std::endl;

	int i = 0;
	for (; i < 5; i++) {
		arr[i] = new Dog();
		std::cout << std::endl;
	}
	for (; i < 10; i++) {
		arr[i] = new Cat();
		std::cout << std::endl;
	}

	for (i = 0; i < 10; i++) {
		std::cout << i << ". ";
		delete arr[i];
		std::cout << std::endl;
	}

	Dog new_dog;
	new_dog.thinking("hungry...");
	std::cout << std::endl;
	Dog copy_dog(new_dog);
	std::cout << copy_dog.speaking(0) << std::endl;
	std::cout << std::endl;

	return 0;
}
