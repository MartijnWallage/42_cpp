/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:37:54 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/22 15:31:59 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main( int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}

	// parse input as map
	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
	{
		std::cerr << "Failed to open " << argv[1] << "." << std::endl;
		return 2;
	}
	std::map<std::string, float> inputMap;
	std::string line;
	while (std::getline(inputFile, line))
	{
		std::istringstream iss(line);
		std::string date;
		float value;
		char dash;
		if (std::getline(iss, date, '|') && iss >> value >> dash) {
			inputMap[date] = value;
		} else {
			std::cerr << "Error parsing line in input: " << line << std::endl;
		}
	}
	inputFile.close();

	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cerr << "Failed to open data.csv." << std::endl;
		return 2;		
	}

	std::map<std::string, float> dataMap;
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date;
		float value;
		char comma;
		if (std::getline(iss, date, ',') && iss >> value >> comma) {
			dataMap[date] = value;
		} else {
			std::cerr << "Error parsing line in database: " << line << std::endl;
		}
	}
	file.close();

	// loop through input map. For each line:
		// find nearest data in data.csv, return exchange value
		// multiply exchange value with given amount
		// output result

	return 0;
}