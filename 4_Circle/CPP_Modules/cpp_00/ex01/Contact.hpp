/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:46:27 by takwak            #+#    #+#             */
/*   Updated: 2025/05/04 16:18:23 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact {
private: 
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

public:
	void	SetFirstName(std::string first_name);
	void	SetLastName(std::string last_name);
	void	SetNickname(std::string nickname);
	void	SetPhoneNumber(std::string phone_number);
	void	SetDarkestSecret(std::string darkest_secret);

	std::string	GetFirstName(void);
	std::string	GetLastName(void);
	std::string	GetNickname(void);

	void	print(void);
};

#endif
