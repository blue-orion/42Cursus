/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:00:26 by takwak            #+#    #+#             */
/*   Updated: 2025/04/18 20:57:23 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileManager.hpp"
#include <iostream>

int	main( int argc, char **argv ) {
	std::string	text;

	if (argc != 4) {
		std::cerr << "Usage: ./filemanager [filename to read] [to_change_string] [replace_string]" << std::endl;
		return 1;
	}
	try {
		text = FileManager::readFile(argv[1]);
		FileManager::replaceString(text, argv[2], argv[3]);

		FileManager::saveToFile(argv[1], text);
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	return 0;
}
