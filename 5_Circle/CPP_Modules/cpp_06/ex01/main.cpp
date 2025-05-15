/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:07:57 by takwak            #+#    #+#             */
/*   Updated: 2025/05/15 18:07:57 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <stdint.h>
#include <iostream>

int	main(void) {
	Data		a[2];
	uintptr_t	raw;

	raw = Serializer::serialize(a);
	std::cout << "original address : " << a << std::endl;
	std::cout << "serialized num   : " << raw << std::endl;
	std::cout << "deserialized add : " << Serializer::deserialize(raw) << std::endl;

	std::cout << std::endl;

	raw = Serializer::serialize(a + 1);
	std::cout << "original address : " << a + 1 << std::endl;
	std::cout << "serialized num   : " << raw << std::endl;
	std::cout << "deserialized add : " << Serializer::deserialize(raw) << std::endl;
}
