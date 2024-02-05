#include "Harl.hpp"
#include <string>
#include <iostream>

//	Public functions

void	Harl::complain( std::string level ) {
	std::map<std::string, void (Harl::*)(void)>::iterator	it = complaints.find(level);
	if (it != complaints.end()) {
		(this->*(it->second))();
	} else {
		std::cout << "This level of complaint does not exist: " << level << std::endl;
	}
}

Harl::Harl( void ) {
	complaints["DEBUG"] = &Harl::debug;
	complaints["INFO"] = &Harl::info;
	complaints["WARNING"] = &Harl::warning;
	complaints["ERROR"] = &Harl::error;

	std::cout << "Harl created" << std::endl;
}

Harl::~Harl( void ) {
	std::cout << "Harl destroyed" << std::endl;
}

//	Private functions

void	Harl::debug( void ) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn\'t put enough bacon in my burger! If you did, I wouldn\'t be asking for more!" << std::endl;

}

void	Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I\'ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void ) {
	std::cerr << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
