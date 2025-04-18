/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:58:19 by takwak            #+#    #+#             */
/*   Updated: 2025/04/18 20:58:19 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	FileManager {

public:
	static void	replaceString( std::string &text, const std::string &to_change, const std::string &replacement);
	static std::string	readFile( const std::string &filename );
	static void	saveToFile( const std::string &filename, const std::string &text );
};
