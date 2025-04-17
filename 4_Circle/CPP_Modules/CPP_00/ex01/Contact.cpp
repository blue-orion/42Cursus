/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:55:27 by takwak            #+#    #+#             */
/*   Updated: 2025/04/16 20:45:55 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::set_first_name(std::string first_name) {
	this->first_name = first_name;
}
void	Contact::set_last_name(std::string last_name) {
	this->last_name = last_name;
}
void	Contact::set_nickname(std::string nickname) {
	this->nickname = nickname;
}
void	Contact::set_phone_number(std::string phone_number) {
	this->phone_number = phone_number;
}
void	Contact::set_darkest_secret(std::string darkest_secret) {
	this->darkest_secret = darkest_secret;
}

std::string Contact::get_first_name(void) {
	return (this->first_name);
}
std::string Contact::get_last_name(void) {
	return (this->last_name);
}
std::string Contact::get_nickname(void) {
	return (this->nickname);
}
std::string Contact::get_phone_number(void) {
	return (this->phone_number);
}
std::string Contact::get_darkest_secret(void) {
	return (this->darkest_secret);
}
