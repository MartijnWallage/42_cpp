/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:41:58 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/12 19:21:15 by mwallage         ###   ########.fr       */
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


void	ScalarConverter::printChar( std::string const & input) {
	std::istringstream	iss(input);
	int					intValue;

	iss >> intValue;
	if (iss.fail())
		std::cout << "impossible" << std::endl;
	else if (!isprint(intValue))
		std::cout << "not printable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(intValue) << "'" << std::endl;
}

void	ScalarConverter::printInt( std::string const & input) {
	int	value;
	std::istringstream	iss(input);
	
	iss >> value;
	if (iss.fail())
		std::cout << "impossible" << std::endl;
	else
		std::cout << value << std::endl;
}

void	ScalarConverter::printFloat( std::string const & input) {
	float	value;
	std::istringstream	iss(input);

	iss >> value;
	if (iss.fail())
		std::cout << "impossible" << std::endl;
	else {
		std::cout << value;
		if (input.find('.') == std::string::npos) {
			std::cout << ".0";
		}
		std::cout << "f" << std::endl;
	}
}

void	ScalarConverter::printDouble( std::string const & input) {
	double	value;
	std::istringstream	iss(input);

	iss >> value;
	if (iss.fail())
		std::cout << "impossible" << std::endl;
	else {
		std::cout << value;
		if (input.find('.') == std::string::npos) {
			std::cout << ".0";
		}
		std::cout << std::endl;
	}
}
