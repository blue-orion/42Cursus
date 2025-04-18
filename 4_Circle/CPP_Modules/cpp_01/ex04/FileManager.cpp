/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:02:17 by takwak            #+#    #+#             */
/*   Updated: 2025/04/18 21:02:17 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileManager.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

std::string	FileManager::readFile( const std::string &filename ) {
	std::string			text;
	std::stringstream	ss;

	std::ifstream 		ifs(filename.c_str());
	if (ifs.fail()) {
		throw std::runtime_error(filename + ": No such file or directory");
	}
	ss << ifs.rdbuf();
	text = ss.str();
	if (text.empty()) {
		throw std::runtime_error(filename + ": Is empty file");
	}
	ifs.close();
	return (text);
}

void	FileManager::replaceString( std::string &text, const std::string &to_change, const std::string &replacement) {
	std::size_t	found;

	found = text.find(to_change, 0);
	while (found != std::string::npos) {
		text.erase(found, to_change.length());
		text.insert(found, replacement);
		found = text.find(to_change, found + replacement.length());
	}
}

void	FileManager::saveToFile( const std::string &filename, const std::string &text ) {
	std::ofstream ofs((filename + ".replace").c_str());

	ofs << text;
	ofs.close();
}
