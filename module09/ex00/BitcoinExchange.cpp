/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:37:49 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/23 18:51:04 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char const * filename)
	: _dataMap(_parseData())
{
	_inputFile.open(filename);
	if (!_inputFile.is_open())
		throw BadFileException();
}

BitcoinExchange::~BitcoinExchange()
{
	_inputFile.close();
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

void BitcoinExchange::compute() 
{
	std::string line;

	while (std::getline(_inputFile, line))
	{
		std::istringstream iss(line);
		std::string date;
		float value;
		if (std::getline(iss, date, '|') && iss >> value)
		{
			date.erase(date.find_last_not_of(" \n\r\t") + 1);
			std::map<std::string, float>::iterator lo = _dataMap.lower_bound(date);
			if (lo != _dataMap.begin()) {
					--lo;
				std::cout << date << " => " << value << " = " << value * lo->second << std::endl;
			}
		}
		else
		{
			std::cout << "Error: bad input" << std::endl;
		}
	}
	_inputFile.close();
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
