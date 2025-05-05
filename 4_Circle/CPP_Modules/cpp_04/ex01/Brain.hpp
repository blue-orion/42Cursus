/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:00:13 by takwak            #+#    #+#             */
/*   Updated: 2025/05/05 22:37:02 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Brain {
private:
	std::string ideas[100];
	int			index;

public:
	Brain();
	~Brain();
	Brain(const Brain& other);
	Brain&	operator=(const Brain& other);

	void		setIdea(std::string contents);
	std::string	getIdea(int index) const;
};
