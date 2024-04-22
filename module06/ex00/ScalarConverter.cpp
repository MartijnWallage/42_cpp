/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:41:58 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/22 13:56:57 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isNan(float x)
{
	return x != x;
}

bool isInf(float x)
{
	return x == std::numeric_limits<float>::infinity() || x == -std::numeric_limits<float>::infinity();
}

bool isNan(double x)
{
	return x != x;
}

bool isInf(double x)
{
	return x == std::numeric_limits<double>::infinity() || x == -std::numeric_limits<double>::infinity();
}

/* ScalarConverter::ScalarConverter( void ) {
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
} */

bool ScalarConverter::isChar(std::string const &input)
{
	return input.size() == 3 && input[0] == '\'' && input[2] == '\'';
}

bool ScalarConverter::isInt(std::string const &input)
{
	size_t i = 0;

	if (input[0] == '+' || input[0] == '-')
		i++;
	while (i < input.length())
	{
		if (isdigit(input[i]))
			i++;
		else
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(std::string const &input)
{
	if (input == "nanf" || input == "+inff" || input == "-inff")
		return true;
	if (input == "nan" || input == "+inf" || input == "-inf")
		return false;

	int dotCounter = 0;
	size_t i = 0;

	if (input[i] == '+' || input[i] == '-')
		i++;
	if (!isdigit(input[i]))
		return false;
	for (size_t i = 1; i < input.length(); i++)
	{
		if (input[i] == 'f' && i == input.length() - 1)
			return true;
		if (!isdigit(input[i]) && input[i] != '.')
			return false;
		dotCounter += (input[i] == '.');
		if (dotCounter > 1)
			return false;
	}
	return false;
}

bool ScalarConverter::isDouble(std::string const &input)
{
	if (input == "nan" || input == "+inf" || input == "-inf")
		return true;

	int dotCounter = 0;
	size_t i = 0;

	if (input[i] == '+' || input[i] == '-')
		i++;
	if (!isdigit(input[i]))
		return false;
	for (size_t i = 1; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '.')
			return false;
		dotCounter += (input[i] == '.');
		if (dotCounter > 1)
			return false;
	}
	return true;
}

char ScalarConverter::convertChar(std::string const &input)
{
	return input[1];
}

int ScalarConverter::convertInt(std::string const &input)
{
	int n;
	std::istringstream iss(input);

	iss >> n;
	if (iss.fail())
		throw ScalarConverter::ConversionFailException();
	return n;
}

float ScalarConverter::convertFloat(std::string const &input)
{
	float f;
	std::istringstream iss(input);

	if (input == "nanf")
		return std::numeric_limits<float>::quiet_NaN();
	if (input == "+inff")
		return std::numeric_limits<float>::infinity();
	if (input == "-inff")
		return -std::numeric_limits<float>::infinity();
	iss >> f;
	if (iss.fail())
		ScalarConverter::ConversionFailException();
	return f;
}

double ScalarConverter::convertDouble(std::string const &input)
{
	double d;
	std::istringstream iss(input);

	if (input == "nan")
		return std::numeric_limits<double>::quiet_NaN();
	if (input == "+inf")
		return std::numeric_limits<double>::infinity();
	if (input == "-inf")
		return -std::numeric_limits<double>::infinity();
	iss >> d;
	if (iss.fail())
		throw ScalarConverter::ConversionFailException();
	return d;
}

void ScalarConverter::printTable(char const c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::printTable(int const n)
{
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

void ScalarConverter::printTable(float const f)
{
	int n = static_cast<int>(f);

	if (isNan(f) || isInf(f) || n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (n < 32 || n > 126)
		std::cout << "char: not printable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

	if (isNan(f) || isInf(f) || f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << n << std::endl;

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::printTable(double const d)
{
	int n = static_cast<int>(d);

	if (isNan(d) || isInf(d) || n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (n < 32 || n > 126)
		std::cout << "char: not printable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

	if (isNan(d) || isInf(d) || d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << n << std::endl;

	std::cout << std::fixed << std::setprecision(1);
	float f = static_cast<float>(d);
	if (!isinf(d) && (d < static_cast<double>(FLT_MIN) || d > static_cast<double>(FLT_MAX)))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;

	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(std::string const &input)
{
	if (input.empty())
		throw ScalarConverter::EmptyInputException();
	if (isChar(input))
	{
		std::cout << "It's a char" << std::endl;
		char c = convertChar(input);
		printTable(c);
	}
	else if (isInt(input))
	{
		std::cout << "It's an int" << std::endl;
		int n = convertInt(input);
		printTable(n);
	}
	else if (isFloat(input))
	{
		std::cout << "It's a float" << std::endl;
		float f = convertFloat(input);
		printTable(f);
	}
	else if (isDouble(input))
	{
		std::cout << "It's a double" << std::endl;
		double d = convertDouble(input);
		printTable(d);
	}
	else
		throw ScalarConverter::UnknownTypeException();
}

const char *ScalarConverter::ConversionFailException::what() const throw()
{
	return "convert: error: initial conversion failed";
}

const char *ScalarConverter::EmptyInputException::what() const throw()
{
	return "convert: error: input empty";
}

const char *ScalarConverter::UnknownTypeException::what() const throw()
{
	return "convert: error: unknown variable type";
}
