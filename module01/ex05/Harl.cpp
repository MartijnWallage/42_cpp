/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:21:11 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/29 16:57:30 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>
#include <iostream>

//	Public functions

void	Harl::complain( std::string type ) {

	int	level = _getLevel(type);

	(this->*complaints[level])();

}

Harl::Harl( void ) {

	complaints[0] = &Harl::_debug;
	complaints[1] = &Harl::_info;
	complaints[2] = &Harl::_warning;
	complaints[3] = &Harl::_error;
	complaints[4] = &Harl::_unknown;

	_levels[0] = "DEBUG";
	_levels[1] = "INFO";
	_levels[2] = "WARNING";
	_levels[3] = "ERROR";

}

Harl::~Harl( void ) {}

//	Private functions

int	Harl::_getLevel( std::string type ) const {

	for (int i = 0; i < 4; i++) {
		if (_levels[i] == type)
			return i;
	}

	return 4;

}

void	Harl::_unknown( void ) {

	std::cout << "I'm unhappy but I don't know why!" << std::endl;

}

void	Harl::_debug( void ) {

	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;

}

void	Harl::_info( void ) {

	std::cout << "I cannot believe adding extra bacon costs more money. You didn\'t put enough bacon in my burger! If you did, I wouldn\'t be asking for more!" << std::endl;

}

void	Harl::_warning( void ) {

	std::cout << "I think I deserve to have some extra bacon for free. I\'ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error( void ) {

	std::cerr << "This is unacceptable! I want to speak to the manager now." << std::endl;

}
