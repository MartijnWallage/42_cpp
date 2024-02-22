/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:21:34 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/22 14:21:36 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>
#include <iostream>

//	Public functions

void	Harl::complain( std::string type ) {

	int	level = getLevel(type);

	if (level == 4) {
		type = "Probably complaining about insignificant problems";
	}
	std::cout << "[ " << type << " ]" << std::endl;
	switch (level) {
		case 0:
			(this->*complaints[0])();
		case 1:
			(this->*complaints[1])();
		case 2:
			(this->*complaints[2])();
		case 3:
			(this->*complaints[3])();
	}

}


Harl::Harl( void ) {

	complaints[0] = &Harl::debug;
	complaints[1] = &Harl::info;
	complaints[2] = &Harl::warning;
	complaints[3] = &Harl::error;

	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";

}

Harl::~Harl( void ) {}

//	Private functions

int	Harl::getLevel( std::string type ) const {

	for (int i = 0; i < 4; i++) {
		if (levels[i] == type)
			return i;
	}

	return 4;

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
