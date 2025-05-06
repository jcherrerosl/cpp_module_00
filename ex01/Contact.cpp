/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanherr <juanherr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:59:46 by juanherr          #+#    #+#             */
/*   Updated: 2025/05/06 12:59:50 by juanherr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact()
	: firstName(""), lastName(""), nickname(""),
	  phoneNumber(""), darkestSecret("") {}

void Contact::setInfo() {
	std::cout << "First name: ";
	std::getline(std::cin >> std::ws, firstName);

	std::cout << "Last name: ";
	std::getline(std::cin >> std::ws, lastName);

	std::cout << "Nickname: ";
	std::getline(std::cin >> std::ws, nickname);

	std::cout << "Phone number: ";
	std::getline(std::cin >> std::ws, phoneNumber);

	std::cout << "Darkest secret: ";
	std::getline(std::cin >> std::ws, darkestSecret);
}

// Getters
std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }
