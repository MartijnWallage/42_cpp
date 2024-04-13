/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:41:58 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/13 19:12:10 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalarConverter.hpp"

scalarConverter::scalarConverter( void ) {
	std::cout << "We'll never see this constructor construct anything." << std::endl;
}

scalarConverter::scalarConverter( scalarConverter const & ) {
	std::cout << "We'll never see this copy constructor copy construct anything." << std::endl;
}

scalarConverter & scalarConverter::operator=( scalarConverter const &) {
	std::cout << "We'll never see this copy assignment copy assign anything." << std::endl;
	return *this;
}

scalarConverter::~scalarConverter( void ) {
	std::cout << "We'll never see this destructor destruct anything." << std::endl;
}

bool scalarConverter::isChar( std::string const & input ) {
 	return input.size() == 3 && input[0] == '\'' && input[2] == '\'';
}

bool scalarConverter::isInt( std::string const & input ) {
	size_t	i = 0;

	if (input[i] == '+' || input[i] == '-')
		i++;
	while (i < input.length()) {
		if (isdigit(input[i]))
			i++;
		else
			return false;
	}
	return true;
}

bool scalarConverter::isFloat( std::string const & input ) {
	return input.find('f') != std::string::npos;
}

bool scalarConverter::isDouble( std::string const & input ) {
	return input.find('.') != std::string::npos;
}

//	std::strtol()
// std::strtof()
// std::strtod()

void	scalarConverter::printChar( std::string const & input) {
//	long int	temp = std::strtol(input.c_str(), NULL, 10);

	std::istringstream	iss(input);
	int					intValue;

	iss >> intValue;
	if (iss.fail())
		std::cout << "impossible" << std::endl;
	else if (intValue < 32 || intValue > 126)
		std::cout << "not printable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(intValue) << "'" << std::endl;
}

void	scalarConverter::printInt( std::string const & input) {
	int					value;
	std::istringstream	iss(input);
	
	iss >> value;
	if (iss.fail())
		std::cout << "impossible" << std::endl;
	else
		std::cout << value << std::endl;
}

void	scalarConverter::printFloat( std::string const & input) {
	float				value;
	std::istringstream	iss(input);
	std::string			test;

	iss >> value;
	if (iss.fail())
		std::cout << "impossible" << std::endl;
	else {
		std::cout << value;
		iss >> test;
		if (test.find('.') == std::string::npos) {
			std::cout << ".0";
		}
		std::cout << "f" << std::endl;
	}
}

void	scalarConverter::printDouble( std::string const & input) {
	double				value;
	std::istringstream	iss(input);
	std::string			test;

	iss >> value;
	if (iss.fail())
		std::cout << "impossible" << std::endl;
	else {
		std::cout << value;
		iss >> test;
		if (test.find('.') == std::string::npos) {
			std::cout << ".0";
		}
		std::cout << std::endl;
	}
}
