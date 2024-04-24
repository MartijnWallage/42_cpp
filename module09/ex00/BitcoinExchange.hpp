/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:37:51 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/24 14:42:33 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstdlib>
#include <utility>
#include <stdexcept>

class BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();

	void compute(const char *filename);

private:
	BitcoinExchange(BitcoinExchange const &);
	BitcoinExchange &operator=(BitcoinExchange const &);

	std::map<std::string, float> _dataMap;
	std::ifstream _inputFile;
	float _value;
	std::string _date;

	std::map<std::string, float> &_parseData();
	bool _isValidDate(std::string const &);
	bool _isValidInput(std::string const &line);

	class BadInputException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class NotOpenFileException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class BadDataException : public std::exception
	{
		virtual const char *what() const throw();
	};
};
