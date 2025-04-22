/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:05:08 by takwak            #+#    #+#             */
/*   Updated: 2025/04/22 00:13:47 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main( void ) {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "      str variable address: " << &str << std::endl;
	std::cout << "stringPTR variable address: " << stringPTR << std::endl;
	std::cout << "stringREF variable address: " << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "      str variable value: " << str << std::endl;
	std::cout << "stringPTR variable value: " << *stringPTR << std::endl;
	std::cout << "stringREF variable value: " << stringREF << std::endl;
	std::cout << std::endl;
	
	str = "HI THIS IS CHANGED BRAIN";
	/*stringREF = NULL;*/
	std::cout << "      str variable value: " << str << std::endl;
	std::cout << "stringPTR variable value: " << *stringPTR << std::endl;
	std::cout << "stringREF variable value: " << stringREF << std::endl;
	std::cout << std::endl;
	return 0;
}

