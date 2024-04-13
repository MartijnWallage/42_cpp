/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:41:58 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/13 19:54:08 by mwallage         ###   ########.fr       */
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
	char	c = input[1];
	std::cout << "char: " << input << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	scalarConverter::printInt( std::string const & input) {
	int					n;
	std::istringstream	iss(input);

	iss >> n;
	if (iss.fail()) {
		std::cerr << "conversion failed" << std::endl;
		return ;
	}
	else if (n < 32 || n > 126)
		std::cout << "char: " << "not printable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << std::endl;
}

void	scalarConverter::printFloat( std::string const & input) {
	float				f;
	int					n;
	std::istringstream	iss(input);
	std::string			test;

	iss >> f;
	if (iss.fail()) {
		std::cerr << "conversion failed" << std::endl;
		return ;
	}
	n = static_cast<int>(f);
	if (n < 32 || n > 126)
		std::cout << "char: " << "not printable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	std::cout << "int: " << n << std::endl;
	if (f - n == 0)
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	scalarConverter::printDouble( std::string const & input) {
	double				d;
	int					n;
	std::istringstream	iss(input);
	std::string			test;

	iss >> d;
	if (iss.fail()) {
		std::cerr << "conversion failed" << std::endl;
		return ;
	}
	n = static_cast<int>(d);
	if (n < 32 || n > 126)
		std::cout << "char: " << "not printable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (d - n == 0)
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;	
}

void scalarConverter::convert(std::string const & input) {
	if (isChar(input))
		printChar(input);
	else if (isInt(input))
		printInt(input);
	else if (isFloat(input))
		printFloat(input);
	else if (isDouble(input))
		printDouble(input);
	else
		std::cout << "Unknown type" << std::endl;
}