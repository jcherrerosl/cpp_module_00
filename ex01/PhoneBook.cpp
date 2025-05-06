/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanherr <juanherr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:58:39 by juanherr          #+#    #+#             */
/*   Updated: 2025/05/06 13:41:09 by juanherr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <limits>

PhoneBook::PhoneBook()
	: count(0), oldestIndex(0)
{
}

void PhoneBook::addContact()
{
	if (count < 8)
	{
		contacts[count].setInfo();
		count++;
	}
	else
	{
		contacts[oldestIndex].setInfo();
		oldestIndex = (oldestIndex + 1) % 8;
	}
}

std::string truncate(const std::string &str)
{
	if (str.length() > 10)
	{
		return (str.substr(0, 9) + ".");
	}
	return (str);
}

int	parseInput(std::string &input)
{
	int	number;

	if (input.length() != 1 || !isdigit(input[0]))
	{
		std::cout << "Invalid index. Enter a number 1-8 or 0 to return." << std::endl;
		return (-1);
	}
	number = input[0] - '0';
	if (number < 0 || number > 8)
	{
		std::cout << "Invalid index. Enter a number 1-8 or 0 to return." << std::endl;
		return (-1);
	}
	return (number);
}

void PhoneBook::searchContacts() const
{
	std::cout << std::setw(10) << "Index"
				<< "|"
				<< std::setw(10) << "First name"
				<< "|"
				<< std::setw(10) << "Last name"
				<< "|"
				<< std::setw(10) << "Nickname"
				<< "|" << std::endl;

	for (int i = 0; i < 8; ++i)
	{
		std::cout << std::setw(10) << i + 1 << "|"
					<< std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
					<< std::setw(10) << truncate(contacts[i].getLastName()) << "|"
					<< std::setw(10) << truncate(contacts[i].getNickname()) << "|" << std::endl;
	}

	while (true)
	{
		std::cout << "Enter the index of the contact you want to see "
						"(1-8, 0 to return): ";
		std::string inputStr;
		std::getline(std::cin, inputStr);

		int input;
		input = parseInput(inputStr);
		if (input == 0)
			break ;

		if (input >= 1 && input <= 8)
		{
			const Contact &c = contacts[input - 1];
			std::cout << "First name:\t" << c.getFirstName() << std::endl;
			std::cout << "Last name:\t" << c.getLastName() << std::endl;
			std::cout << "Nickname:\t" << c.getNickname() << std::endl;
			std::cout << "Phone number:\t" << c.getPhoneNumber() << std::endl;
			std::cout << "Darkest secret:\t" << c.getDarkestSecret() << std::endl;
			break ;
		}

		std::cout << "Index out of range. Try again or press 0 to return." << std::endl;
	}
}