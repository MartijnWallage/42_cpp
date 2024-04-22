/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:37:54 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/22 13:48:29 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main( int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}

	// open(argv[1]);
	// if (fail) {exit};
	// parse input as map;
	// parse data.csv as map
	// loop through input map. For each line:
		// if (!isValidInput()) {exit}
		// find nearest data in data.csv, return exchange value
		// multiply exchange value with given amount
		// output result
	return 0;
}