#include "Harl.hpp"
#include <string>
#include <iostream>

//	Public functions


void	Harl::complain( std::string type ) {

	int	level = getLevel(type);

	(this->*complaints[level])();

}

int	Harl::getLevel( std::string type ) const {

	for (int i = 0; i < 4; i++) {
		if (levels[i] == type)
			return i;
	}

	return 4;

}

Harl::Harl( void ) {
	complaints[0] = &Harl::debug;
	complaints[1] = &Harl::info;
	complaints[2] = &Harl::warning;
	complaints[3] = &Harl::error;
	complaints[4] = &Harl::unknown;

	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";

}

Harl::~Harl( void ) {}

//	Private functions

void	Harl::unknown( void ) {

	std::cout << "I'm unhappy but I don't know why!" << std::endl;

}
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
