/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:37:54 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/23 18:45:02 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::multimap<std::string, float> &parseInput(char *filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Failed to open " << filename << "." << std::endl;
		std::exit(2);
	}

	std::string firstline;
	std::getline(file, firstline);
	if (firstline != "date | value")
	{
		std::cerr << "Error parsing first line in input." << std::endl;
		file.close();
		std::exit(2);
	}

	static std::multimap<std::string, float> inputMap;
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date;
		float value;
		if (std::getline(iss, date, '|') && iss >> value)
		{
			date.erase(date.find_last_not_of(" \n\r\t") + 1);
			inputMap.insert(std::make_pair(date, value));
		}
		else
		{
			inputMap.insert(std::make_pair("Error: bad input", 0.0f));
		}
	}
	file.close();
	return inputMap;
}


int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}

	/* 	std::cout << "Data map:" << std::endl;
		for (std::map<std::string, float>::iterator it = dataMap.begin(); it != dataMap.end(); ++it)
		{
			std::cout << "date: " << it->first << "value: " << it->second << std::endl;
		}
		std::cout << "Input map:" << std::endl;
		for (std::map<std::string, float>::iterator it = inputMap.begin(); it != inputMap.end(); ++it)
		{
			std::cout << "date: " << it->first << "value: " << it->second << std::endl;
		} */

	BitcoinExchange be(argv[1]);
	try {
		be.compute();
	} catch (std::exception const & e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}