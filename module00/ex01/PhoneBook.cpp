/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:18:18 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/28 16:12:19 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype>
#include <cstdlib>

// Helper

void	ignoreLine( void )
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Private

PhoneBook::PhoneBook() : _contact_count	(0), _index(0) {}

std::string	PhoneBook::_truncateName(const std::string& str) const
{
	if (str.length() > 10) {
		return str.substr(0, 9) + ".";
	}
	return str;
}

std::string	PhoneBook::_getInput(const std::string& message) const
{
	std::string	input;

	while (true)
	{
		std::cout << message;
		if (std::cin >> input) {
			ignoreLine();
			return (input);
		}
		else if (std::cin.eof())
			return "";
		std::cin.clear();
		ignoreLine();
	}
	return "";
}

//	Public
void	PhoneBook::addContact()
{
	std::string input;

	input = _getInput("Enter first name: ");
	if (input == "")
		return ;
	_contacts[_index].setFirstName(input);
	
	input = _getInput("Enter last name: ");
	if (input == "")
		return ;
	_contacts[_index].setLastName(input);

	input = _getInput("Enter nickname: ");
	if (input == "")
		return ;
	_contacts[_index].setNickname(input);

	input = _getInput("Enter phone number: ");
	if (input == "")
		return ;
	_contacts[_index].setPhoneNumber(input);

	input = _getInput("Enter darkest secret: ");
	if (input == "")
		return ;
	_contacts[_index].setSecret(input);

	_index++;
	_index %= 8;
	if (_contact_count < 8)
		_contact_count++;
}

void	PhoneBook::displayContacts() const
{
	std::cout << std::right << std::setw(10) << "Index" << " | ";
	std::cout << std::right << std::setw(10) << "First name" << " | ";
	std::cout << std::right << std::setw(10) << "Last name" << " | ";
	std::cout << std::right << std::setw(10) << "Nickname" << " | ";
	std::cout << std::right << std::setw(10) << "Phone" << " | ";
	std::cout << std::right << std::setw(10) << "Secret" << " | " << std::endl;
	for (int i = 0; i < _contact_count; i++) {
		std::cout << std::right << std::setw(10) << i << " | ";
		std::cout << std::right << std::setw(10) << _truncateName(_contacts[i].getFirstName()) << " | ";
		std::cout << std::right << std::setw(10) << _truncateName(_contacts[i].getLastName()) << " | ";
		std::cout << std::right << std::setw(10) << _truncateName(_contacts[i].getNickname()) << " | ";
		std::cout << std::right << std::setw(10) << _truncateName(_contacts[i].getPhoneNumber()) << " | ";
		std::cout << std::right << std::setw(10) << _truncateName(_contacts[i].getSecret()) << " | " << std::endl;
	}
}

void	PhoneBook::searchContact() const
{
	int	index;

	if (_contact_count == 0) {
		std::cout << "There are no contacts yet to search for. Add some!" << std::endl;
		return ;
	}
	displayContacts();
	while (true)
	{
		std::cout << "Enter index of phonebook contact to display: ";
		if (std::cin >> index
			&& index >= 0
			&& index < _contact_count) {
			break ;
		}
		else if (std::cin.eof())
			return ;
		std::cin.clear();
		ignoreLine();
	}
	_contacts[index].displayContact();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

PhoneBook::~PhoneBook() {}