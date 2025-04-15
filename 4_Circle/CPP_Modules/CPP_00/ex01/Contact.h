/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:46:27 by takwak            #+#    #+#             */
/*   Updated: 2025/04/15 23:11:38 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <stdlib.h>
# include <iostream>

class	Contact {
private: 
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

public:
	void	set_first_name(std::string first_name) {
		this->first_name = first_name;
	}
	void	set_last_name(std::string last_name) {
		this->last_name = last_name;
	}
	void	set_nickname(std::string nickname) {
		this->nickname = nickname;
	}
	void	set_phone_number(std::string phone_number) {
		this->phone_number = phone_number;
	}
	void	set_darkest_secret(std::string darkest_secret) {
		this->darkest_secret = darkest_secret;
	}

	std::string	get_first_name(void) {
		return (this->first_name);
	}
	std::string	get_last_name(void) {
		return (this->last_name);
	}
	std::string	get_nickname(void) {
		return (this->nickname);
	}
	std::string	get_phone_number(void) {
		return (this->phone_number);
	}
	std::string	get_darkest_secret(void) {
		return (this->darkest_secret);
	}
};

#endif
