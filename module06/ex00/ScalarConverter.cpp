/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:41:58 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/09 19:04:25 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {
	std::cout << "We'll never see this constructor construct anything." << std::endl;
}

ScalarConverter::ScalarConverter( ScalarConverter const & ) {
	std::cout << "We'll never see this copy constructor copy construct anything." << std::endl;
}

ScalarConverter & ScalarConverter::operator=( ScalarConverter const &) {
	std::cout << "We'll never see this copy assignment copy assign anything." << std::endl;
}

ScalarConverter::ScalarConverter( void ) {
	std::cout << "We'll never see this destructor destruct anything." << std::endl;
}

bool	isChar( std::string const & literal ) {
	return literal.length() == 1 && !std::isdigit(literal[0]);
}

bool	isInt( std::string const & literal ) {
	try {
		size_t	pos;
		std::stoll(literal, &pos);
		if (pos == literal.length())
			return true;
	} catch ( std::exception & e ) {
		return false;
	}
	return true;
}

bool	isFloat( std::string const & literal ) {
	try {
		
	}
}

bool	isDouble( std::string const & literal ) {
	
}

void ScalarConverter::convert( std::string const literal ) {
	if (isChar(literal))
			
	// check int
	// check float
	//		-innf, +inff, nanf
	// check double
	//		-inf, +inf, nan
}