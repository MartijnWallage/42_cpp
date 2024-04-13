/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:46:49 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/13 18:44:58 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalarConverter.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2 ) {
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}

	std::string const	input(argv[1]);

	std::cout << "char: ";
	if (scalarConverter::isChar( input ))
		std::cout << input << std::endl;
	else
		scalarConverter::convert<char>(input);

	std::cout << "int: ";
	if (scalarConverter::isInt( input ))
		std::cout << input << std::endl;
	else
		scalarConverter::convert<int>(input);

	std::cout << "float: ";
	if (scalarConverter::isFloat( input ))
		std::cout << input << std::endl;
	else
		scalarConverter::convert<float>(input);

	std::cout << "double: ";
	if (scalarConverter::isDouble( input ))
		std::cout << input << std::endl;
	else
		scalarConverter::convert<double>(input);

    return 0;
}
