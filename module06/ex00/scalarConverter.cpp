/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:41:58 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/14 18:31:25 by mwallage         ###   ########.fr       */
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

	if (input[0] == '+' || input[0] == '-')
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
	if (input == "nanf" || input == "+inff" || input == "-inff")
		return true;
	if (input == "nan" || input == "+inf" || input == "-inf")
		return false;
	return input.find('f') != std::string::npos;
}

bool scalarConverter::isDouble( std::string const & input ) {
	if (input == "nan" || input == "+inf" || input == "-inf")
		return true;
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
	if (iss.fail())
		throw scalarConverter::ConversionFailException();
	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (n < 32 || n > 126)
		std::cout << "char: not printable" << std::endl;
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

	if (input == "nanf" || input == "-inff" || input == "+inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
		return ;
	}
	iss >> f;
	if (iss.fail())
		scalarConverter::ConversionFailException();
	n = static_cast<int>(f);
	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (n < 32 || n > 126)
		std::cout << "char: not printable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << n << std::endl;
	if (f - n == 0)
		std::cout << std::fixed << std::setprecision(1);	// doesn't work for numbers that get rounded off to 0
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	scalarConverter::printDouble( std::string const & input) {
	double				d;
	int					n;
	std::istringstream	iss(input);
	std::string			test;

	if (input == "nan" || input == "-inf" || input == "+inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
		return ;
	}
	iss >> d;
	if (iss.fail())
		throw scalarConverter::ConversionFailException();
	n = static_cast<int>(d);
	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (n < 32 || n > 126)
		std::cout << "char: not printable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	if (d < INT_MIN || d > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << n << std::endl;
	if (d - n == 0)
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;	
}

void scalarConverter::convert(std::string const & input) {
	if (input.empty())
		throw scalarConverter::EmptyInputException();
	if (isChar(input)) {
		std::cout << "it's a char" << std::endl;
		printChar(input);
	}
	else if (isInt(input)) {
				std::cout << "it's an int" << std::endl;
		printInt(input);
	}
	else if (isFloat(input)) {
		std::cout << "it's a float" << std::endl;
		printFloat(input);
	}
	else if (isDouble(input)) {
		std::cout << "it's a double" << std::endl;
		printDouble(input);
	}
	else
		throw scalarConverter::UnknownTypeException();
}

const char*	scalarConverter::ConversionFailException::what() const throw(){
	return "convert: error: initial conversion failed";
}

const char* scalarConverter::EmptyInputException::what() const throw() {
	return "convert: error: input empty";
}

const char* scalarConverter::UnknownTypeException::what() const throw() {
	return "convert: error: unknown variable type";
}
