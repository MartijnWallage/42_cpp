/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:37:49 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/23 16:57:38 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char const &filename)
	: _dataMap(_parseData())
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) : _dataMap(src._dataMap)
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	if (this != &src)
	{
		this->_dataMap = src._dataMap;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

std::map<std::string, float> &BitcoinExchange::_parseData(void)
{

	std::ifstream file("data.csv");
	if (!file.is_open())
		throw BadFileException();

	std::string firstline;
	std::getline(file, firstline);
	if (firstline != "date,exchange_rate")
	{
		file.close();
		throw BadDataException();
	}

	static std::map<std::string, float> dataMap;
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date;
		float value;
		if (std::getline(iss, date, ',') && iss >> value)
		{
			dataMap[date] = value;
		}
		else
		{
			file.close();
			throw BadDataException();
		}
	}
	file.close();
	return dataMap;
}

void BitcoinExchange::compute() const 
{

}

const char* BitcoinExchange::BadFileException::what() const throw()
{
	return "Error: bad file.";
}


const char* BitcoinExchange::TooLargeNumberException::what() const throw()
{
	return "Error: too large a number.";
}

const char* BitcoinExchange::BadInputException::what() const throw() {
	return "Error: bad input.";
}

const char* BitcoinExchange::BadDataException::what() const throw() {
	return "Error: bad data.";
}

const char* BitcoinExchange::NotPositiveNumberException::what() const throw() {
	return "Error: not a positive number.";
}
