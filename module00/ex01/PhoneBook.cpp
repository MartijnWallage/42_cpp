/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:18:18 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/24 08:31:09 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

// Private

PhoneBook::PhoneBook() : contact_count(0) {}

std::string	truncateName(const std::string& str) {
	if (str.length() > 10) {
		return str.substr(0, 9) + ".";
	}
	return str;
}

//	Public

void	PhoneBook::addContact() {
	int index = contact_count;
	std::string input;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	contacts[index].setFirstName(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	contacts[index].setLastName(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	contacts[index].setNickname(input);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	contacts[index].setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	contacts[index].setSecret(input);

	contact_count++;
	contact_count %= 8;
}

void	PhoneBook::displayContacts() const {
	std::cout << std::right << std::setw(10) << "Index" << " | ";
	std::cout << std::right << std::setw(10) << "First name" << " | ";
	std::cout << std::right << std::setw(10) << "Last name" << " | ";
	std::cout << std::right << std::setw(10) << "Nickname" << " | ";
	std::cout << std::right << std::setw(10) << "Phone" << " | ";
	std::cout << std::right << std::setw(10) << "Secret" << " | " << std::endl;
	for (int i = 0; i < contact_count; i++) {
		std::cout << std::right << std::setw(10) << i << " | ";
		std::cout << std::right << std::setw(10) << truncateName(contacts[i].getFirstName()) << " | ";
		std::cout << std::right << std::setw(10) << truncateName(contacts[i].getLastName()) << " | ";
		std::cout << std::right << std::setw(10) << truncateName(contacts[i].getNickname()) << " | ";
		std::cout << std::right << std::setw(10) << truncateName(contacts[i].getPhoneNumber()) << " | ";
		std::cout << std::right << std::setw(10) << truncateName(contacts[i].getSecret()) << " | " << std::endl;
	}
}

void	PhoneBook::searchContact() const {
	int	index;

	displayContacts();
	std::cout << "Enter index of phonebook contact to display: ";
	std::cin >> index;
	std::cin.ignore();

	if (index >= 0 && index < contact_count)
		contacts[index].displayContact();
	else
		std::cout << "Invalid index" << std::endl;
}

PhoneBook::~PhoneBook() {}