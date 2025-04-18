/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:34:09 by takwak            #+#    #+#             */
/*   Updated: 2025/04/18 21:34:09 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	Harl {
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
public:
	void	complain(std::string level);
};
