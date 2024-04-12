/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:46:49 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/12 19:04:21 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

Type	checkType( std::string const & input ) {
 	if (input.size() == 3 && input[0] == '\'' && input[2] == '\'')
		return CHAR;
	if (std::strspn(input.c_str(), "0123456789-+") == input.size())
		return INT;
	if (input.find('f') != std::string::npos)
		return FLOAT;
	if (input.find('.') != std::string::npos)
		return DOUBLE;
	return OTHER;
}

int main(int argc, char* argv[]) {
	if (argc != 2 ) {
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}

	std::string	const input(argv[1]);

	Type	type = checkType(input);
	if (type == OTHER) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return 0;
	}

	std::cout << "char: ";
	if (type == CHAR)
		std::cout << input << std::endl;
	else
		ScalarConverter::convert<char>(input);

	std::cout << "int: ";
	if (type == INT)
		std::cout << input << std::endl;
	else
		ScalarConverter::convert<int>(input);

	std::cout << "float: ";
	if (type == FLOAT)
		std::cout << input << std::endl;
	else
		ScalarConverter::convert<float>(input);

	std::cout << "double: ";
	if (type == DOUBLE)
		std::cout << input << std::endl;
	else
		ScalarConverter::convert<double>(input);

    return 0;
}
