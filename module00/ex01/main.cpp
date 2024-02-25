/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:17:33 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/25 16:09:41 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int	main() {
	PhoneBook	phoneBook;
	std::string	command;

	while (!std::cin.eof()) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "ADD") {
			phoneBook.addContact();
		} else if (command == "SEARCH") {
			phoneBook.searchContact();
		} else if (std::cin.eof()) {
			std::cout << std::endl;
			return 0;
		} else if (command == "EXIT") {
			break ;
		} else {
			std::cout << "Invalid command." << std::endl;
		}
	}
	return (0);
}