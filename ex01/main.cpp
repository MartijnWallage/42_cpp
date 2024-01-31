#include <iostream>
#include "PhoneBook.hpp"

int	main() {
	PhoneBook	phoneBook;
	std::string	command;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::cin >> command;
		std::cin.ignore();

		if (command == "EXIT") {
			break ;
		} else if (command == "ADD") {
			phoneBook.addContact();
		} else if (command == "SEARCH") {
			phoneBook.searchContact();
		} else {
			std::cout << "Invalid command." << std::endl;
		}
	}
	return (0);
}