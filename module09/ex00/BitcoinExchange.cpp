/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:37:49 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/30 17:50:52 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
	: _dataMap(_parseData())
{
}

BitcoinExchange::~BitcoinExchange()
{
}

std::map<std::string, float> &BitcoinExchange::_parseData(void)
{

	std::ifstream file("data.csv");
	if (!file.is_open())
		throw NotOpenFileException();

	std::string firstline;
	std::getline(file, firstline);
	if (firstline != "date,exchange_rate")
		throw BadDataException();

	static std::map<std::string, float> dataMap;
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date;
		float value;
		if (std::getline(iss, date, ',') && iss >> value)
			dataMap[date] = value;
		else
			throw BadDataException();
	}
	file.close();
	return dataMap;
}

bool BitcoinExchange::_isLeapYear(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool BitcoinExchange::_isValidDate(std::string const &date)
{
	std::istringstream iss(date);
	int year, month, day;
	char delimiter;

	if (!(iss >> year >> delimiter >> month >> delimiter >> day))
		return false;
	if (delimiter != '-' || year < 0 || month < 1 || month > 12 || day < 1)
		return false;

	bool isValidDay = false;
	if (month == 2)
		isValidDay = day <= 29 && (day <= 28 || _isLeapYear(year));
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		isValidDay = (day <= 30);
	else
		isValidDay = (day <= 31);

	return isValidDay;
}

bool BitcoinExchange::_isValidInput(std::string const &line)
{
	if (line.length() < 13 || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		return false;

	_date = line.substr(0, 10);
	if (!_isValidDate(_date))
		return false;

	std::istringstream ss(line.substr(13));
	ss >> _value;
	if (ss.fail())
		return false;

	return true;
}

void BitcoinExchange::compute(const char *filename)
{
	_inputFile.open(filename);
	if (!_inputFile.is_open())
		throw NotOpenFileException();

	std::string line;
	std::getline(_inputFile, line);
	if (line != "date | value")
		throw BadInputException();

	while (std::getline(_inputFile, line))
	{
		if (!_isValidInput(line))
			std::cout << "Error: bad input => " << line << std::endl;
		else if (_value < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (_value > 1000)
			std::cout << "Error: too large a number." << std::endl;
		else
		{
			std::map<std::string, float>::iterator lo = _dataMap.lower_bound(_date);
			if (lo != _dataMap.begin())
			{
				--lo;
				std::cout << _date << " => " << _value << " = " << _value * lo->second << std::endl;
			}
			else
				std::cout << "Error: cannot find corresponding data => " << line << std::endl;
		}
	}
	_inputFile.close();
}

const char *BitcoinExchange::NotOpenFileException::what() const throw()
{
	return "Error: could not open file.";
}

const char *BitcoinExchange::BadDataException::what() const throw()
{
	return "Error: bad data.";
}

const char *BitcoinExchange::BadInputException::what() const throw()
{
	return "Error: invalid input file.";
}