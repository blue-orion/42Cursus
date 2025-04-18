/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:00:26 by takwak            #+#    #+#             */
/*   Updated: 2025/04/18 17:36:13 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <sstream>

std::string	readAllFile( std::string filename) {
	std::fstream ifs(filename);
	std::string	text;

	std::string	token;
	/*char	c = ifs.get();*/

	while (std::getline(ifs, token)) {
		text += token + '\n';
	}

	/*while (ifs.good()) {*/
	/*	ifs >> token;*/
	/*	text += token;*/
	/*}*/
	ifs.close();
	return (text);
}

void	substituteString( std::string &text, const std::string &to_change, const std::string &replacement) {
	std::cout << text << std::endl;
	std::cout << to_change << std::endl;
	std::cout << replacement << std::endl;
}

int	main( int argc, char **argv ) {
	std::string	text;

	if (argc != 4)
		return (0);
	text = readAllFile(argv[1]);
	std::cout << "original text" << std::endl
		<< "==========================================================================="
		<< std::endl << text << std::endl
		<< "===========================================================================" << std::endl;
	substituteString(text, static_cast<std::string>(argv[2]), static_cast<std::string>(argv[3]));

}
