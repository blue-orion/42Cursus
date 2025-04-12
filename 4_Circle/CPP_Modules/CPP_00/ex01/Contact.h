/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:46:27 by takwak            #+#    #+#             */
/*   Updated: 2025/04/13 00:50:20 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <stdlib.h>

void	init_string(char *str, int size);
void	strcpy(char *dst, const char *src);

class	Contact {
private: 
	int		index;
	char	first_name[4096];
	char	last_name[4096];
	char	nickname[4096];
	char	phone_number[4096];
	char	darkest_secret[4096];

public:
	Contact(void) {
		init_string(this->first_name, 4096);
		init_string(this->last_name, 4096);
		init_string(this->nickname, 4096);
		init_string(this->phone_number, 4096);
		init_string(this->darkest_secret, 4096);
	}

	~Contact(void);

	Contact(const Contact& other) {
		this->index = other.index;
		strcpy(first_name, other.first_name);
		strcpy(last_name, other.last_name);
		strcpy(nickname, other.nickname);
		strcpy(phone_number, other.phone_number);
		strcpy(darkest_secret, other.darkest_secret);
	}

	Contact& operator=(const Contact& other) {
		if (this == &other)
			return *this;
		this->index = other.index;
		strcpy(first_name, other.first_name);
		strcpy(last_name, other.last_name);
		strcpy(nickname, other.nickname);
		strcpy(phone_number, other.phone_number);
		strcpy(darkest_secret, other.darkest_secret);
		
		return *this;
	}
};

#endif
