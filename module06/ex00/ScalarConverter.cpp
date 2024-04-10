/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:41:58 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/10 17:48:50 by mwallage         ###   ########.fr       */
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

bool	ScalarConverter::isSpecialFloat( const std::string & str ) {
	return str == "-inff" || str == "+inff" || str == "nanf";
}

bool	ScalarConverter::isSpecialDouble( const std::string & str ) {
	return str == "-inf" || str == "+inf" || str == "nan";
}

std::string ScalarConverter::getCharValue( void ) {
	if (_type == CHAR)
		return _str;
	return "Non-displayable";
}

std::string ScalarConverter::getIntValue( void ) {

}

std::string ScalarConverter::getFloatValue( void ) {

}

std::string ScalarConverter::getDoubleValue( void ) {
	
}

bool	ScalarConverter::isChar() {
	return _str.length() == 3 && _str[0] == '\'' && _str[2] == '\'';
}

void ScalarConverter::convert(const std::string str) {
	_str = str;

	//	recognise type
	if (isChar()) _type == CHAR;
	else if (isInt()) _type == INT;
	else if (isFloat()) _type == FLOAT;
	else if (isDouble()) _type == DOUBLE;
	else _type == OTHER;
	
	std::cout << "char: " << getCharValue() << std::endl;
	std::cout << "int: " << getIntValue() << std::endl;
	std::cout << "float: " << getFloatValue() << std::endl;
	std::cout << "double: " << getDoubleValue() << std::endl;

	
        // Handle special float and double values
        if (isSpecialFloat(literal)) {
			std::cout << "char: n/a; int: n/a; float: " << literal << "; double: n/a" << std::endl;
			return ;
		}
		if (isSpecialDouble(literal)) {
            std::cout << "char: n/a; int: n/a; float: n/a; double: " << literal << std::endl;
            return;
        }

        // Attempt conversion to char if the literal is a single character (excluding special cases)
        if (literal.size() == 1) {
            char c = literal[0];
            std::cout << "char: " << c << "; int: " << static_cast<int>(c)
                      << "; float: " << static_cast<float>(c)
                      << "; double: " << static_cast<double>(c) << std::endl;
            return;
        }

        // Attempt conversion to int, float, and double
        int i = std::atoi(literal.c_str());
        float f = std::atof(literal.c_str());
        double d = std::atof(literal.c_str());

        std::cout << "char: ";
        if (i >= 0 && i <= 255) {
            char c = static_cast<char>(i);
            if (isprint(c)) {
                std::cout << c;
            } else {
                std::cout << "non-displayable";
            }
        } else {
            std::cout << "impossible";
        }
        std::cout << ", int: " << i << ", float: " << f << ", double: " << d << std::endl;
}
