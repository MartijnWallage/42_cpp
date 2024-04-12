/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:41:58 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/12 17:25:38 by mwallage         ###   ########.fr       */
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
	return *this;
}

ScalarConverter::~ScalarConverter( void ) {
	std::cout << "We'll never see this destructor destruct anything." << std::endl;
}

void	ScalarConverter::convert( const std::string & input )
{
	std::cout << "Test: " << input << std::endl;

	// Detecting the type
	bool isChar = input.size() == 3 && input[0] == '\'' && input[2] == '\'';
	bool isInt = std::strspn(input.c_str(), "0123456789-+") == input.size();
    bool isFloat = input.find('f') != std::string::npos;
	bool isDouble = input.find('.') != std::string::npos && !isFloat;
	
	// Initial assumption about types
	char asChar = '\0';
	int asInt = 0;
	float asFloat = 0.0f;
	double asDouble = 0.0;

	if (isChar) {
    	asChar = input[1];
		if (isprint(asChar))
			std::cout << "char: " << asChar << std::endl;
		else
			std::cout << "char: not printable" << std::endl;
    } else {
    	std::cout << "char: impossible" << std::endl;
    }

	if (isInt && !isFloat && !isDouble) {
		asInt = atoi(input.c_str());
        std::cout << "int: " << asInt << std::endl;
    } else {
		std::cout << "int: impossible" << std::endl;
    }

	if (isFloat) {
		if (input == "-inff") asFloat = -INFINITY;
        else if (input == "+inff") asFloat = INFINITY;
        else if (input == "nanf") asFloat = NAN;
        else asFloat = static_cast<float>(atof(input.c_str()));
        std::cout << "float: " << asFloat << "f" << std::endl;
    } else if (isDouble) {
        std::cout << "float: impossible" << std::endl;
    } else {
		asFloat = static_cast<float>(atof(input.c_str()));
		std::cout << "float: " << asFloat << "f" << std::endl;
    }

	if (isDouble) {
		if (input == "-inf") asDouble = -INFINITY;
		else if (input == "+inf") asDouble = INFINITY;
		else if (input == "nan") asDouble = NAN;
		else asDouble = atof(input.c_str());
        std::cout << "double: " << asDouble << std::endl;
    } else {
		asDouble = atof(input.c_str());
		std::cout << "double: " << asDouble << std::endl;
	}
}
