/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:37:49 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/23 19:24:29 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char const *filename)
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

bool _isValidFormat(std::string const & line)
{
	return line.length() > 13;
}

bool _isValidDate(std::string const & date)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (!std::isdigit(date[i]))
			return false;
	}
	if (date[4] != '-')
		return false;
	if (!std::isdigit(date[5]) || !std::isdigit(date[6]))
		return false;
	if (date[7] != '-')
		return false;
	if (!std::isdigit(date[8]) || !std::isdigit(date[9]))
		return false;
	return true;
}

float _getValue(std::string const & line)
{

	size_t pipePos = line.find_first_of('|');

    char* endPtr;
    float floatValue = std::strtof(&line[pipePos + 2], &endPtr);

    return floatValue;

/* 	   size_t pipePos = input.find('|');
    if (pipePos == std::string::npos) {
        std::cerr << "Error: '|' character not found in the string." << std::endl;
        return 1;
    }

    // Create an istringstream from the substring after '|'
    std::istringstream iss(input.substr(pipePos + 1));

    // Attempt to extract a float from the istringstream
    float floatValue;
    if (!(iss >> floatValue)) {
        std::cerr << "Error: Failed to extract a valid floating-point number after '|'." << std::endl;
        return 1;
    }

    std::cout << "Float value: " << floatValue << std::endl; */
}

void BitcoinExchange::compute()
{
	std::string line;

	while (std::getline(_inputFile, line))
	{
		if (!_isValidFormat(line))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string const date(line.substr(0, 10));
		if (!_isValidDate(date))
		{
			std::cout << "Error: bad date => " << line << std::endl;
			continue;
		}
		float value = _getValue(line);
		if (value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		} else if (value > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, float>::iterator lo = _dataMap.lower_bound(date);
		if (lo != _dataMap.begin())
		{
			--lo;
			std::cout << date << " => " << value << " = " << value * lo->second << std::endl;
		}
		else
		{
			std::cout << "Error: bad input => " << line << std::endl;
		}
	}
	_inputFile.close();
}

const char *BitcoinExchange::BadFileException::what() const throw()
{
	return "Error: bad file.";
}

const char *BitcoinExchange::BadDataException::what() const throw()
{
	return "Error: bad data.";
}
