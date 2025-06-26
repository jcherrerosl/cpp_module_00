/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanherr <juanherr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:59:46 by juanherr          #+#    #+#             */
/*   Updated: 2025/06/26 11:27:06 by juanherr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact()
  : _firstName(""), _lastName(""), _nickname(""),
    _phoneNumber(""), _darkestSecret("")
{
}

void Contact::setInfo()
{
	std::cout << "First name: ";
	std::getline(std::cin >> std::ws, _firstName);
	std::cout << "Last name: ";
	std::getline(std::cin >> std::ws, _lastName);
	std::cout << "Nickname: ";
	std::getline(std::cin >> std::ws, _nickname);
	std::cout << "Phone number: ";
	std::getline(std::cin >> std::ws, _phoneNumber);
	std::cout << "Darkest secret: ";
	std::getline(std::cin >> std::ws, _darkestSecret);
}

std::string Contact::getFirstName() const
{
	return (_firstName);
}

std::string Contact::getLastName() const
{
	return (_lastName);
}

std::string Contact::getNickname() const
{
	return (_nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (_phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (_darkestSecret);
}
