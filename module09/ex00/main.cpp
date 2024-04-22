/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:37:54 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/22 17:05:59 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


std::multimap<std::string, int> & parseInput( char* filename)
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
			std::cerr << "Error parsing first line in input."<< std::endl;
			file.close();
			std::exit(2);
	}

	static std::multimap<std::string, int> inputMap;
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date;
		int value;
		if (std::getline(iss, date, '|') && iss >> value) {
			date.erase(date.find_last_not_of(" \n\r\t") + 1);
			inputMap.insert(std::make_pair(date, value));
		} else {
			std::cerr << "Error parsing line in input: " << line << std::endl;
			file.close();
			std::exit(2);
		}
	}
	file.close();
	return inputMap;
}

std::map<std::string, float> & parseData( void )
{

	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cerr << "Failed to open data.csv." << std::endl;
		std::exit(2);	
	}

	std::string firstline;
	std::getline(file, firstline);
	if (firstline != "date,exchange_rate")
	{
			std::cerr << "Error parsing first line in data.csv."<< std::endl;
			file.close();
			std::exit(2);
	}

	static std::map<std::string, float> dataMap;
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date;
		float value;
		if (std::getline(iss, date, ',') && iss >> value) {
			dataMap[date] = value;
		} else {
			std::cerr << "Error parsing line in database: " << line << std::endl;
			file.close();
			std::exit(2);
		}
	}
	file.close();
	return dataMap;
}

int main( int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}

	std::multimap<std::string, int> & inputMap = parseInput(argv[1]);
	std::map<std::string, float> & dataMap = parseData();

	std::cout << "Data map:" << std::endl;
	for (std::map<std::string, float>::iterator it = dataMap.begin(); it != dataMap.end(); ++it)
	{
		std::cout << "date: " << it->first << "value: " << it->second << std::endl;
	}
	std::cout << "Input map:" << std::endl;
	for (std::map<std::string, int>::iterator it = inputMap.begin(); it != inputMap.end(); ++it)
	{
		std::cout << "date: " << it->first << "value: " << it->second << std::endl;
	}
	// loop through input map. For each line:
		// find nearest data in data.csv, return exchange value
		// multiply exchange value with given amount
		// output result

	return 0;
}