/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:55:27 by takwak            #+#    #+#             */
/*   Updated: 2025/04/17 22:03:53 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::SetFirstName(std::string first_name) {
	this->first_name = first_name;
}
void	Contact::SetLastName(std::string last_name) {
	this->last_name = last_name;
}
void	Contact::SetNickname(std::string nickname) {
	this->nickname = nickname;
}
void	Contact::SetPhoneNumber(std::string phone_number) {
	this->phone_number = phone_number;
}
void	Contact::SetDarkestSecret(std::string darkest_secret) {
	this->darkest_secret = darkest_secret;
}

std::string	Contact::GetFirstName(void) {
	return (this->first_name);
}
std::string	Contact::GetLastName(void) {
	return (this->last_name);
}
std::string	Contact::GetNickname(void) {
	return (this->nickname);
}

void	Contact::print(void) {
	std::cout << "first name : " << first_name << std::endl
			<< "last name : " << last_name << std::endl
			<< "nickname : " << nickname << std::endl
			<< "phone number : " << phone_number << std::endl
			<< "darkest secret : " << darkest_secret << std::endl;
}
