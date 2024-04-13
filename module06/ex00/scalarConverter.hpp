/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:36:45 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/13 18:37:35 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstring>
#include <limits>
#include <typeinfo>

enum Type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	OTHER
};

class scalarConverter {
private:
    scalarConverter();
	scalarConverter( scalarConverter const & );
	scalarConverter& operator=( scalarConverter const &);

public:
	~scalarConverter();
	
	static bool isChar( std::string const & input );
	static bool isInt( std::string const & input );
	static bool isFloat( std::string const & input );
	static bool isDouble( std::string const & input );

	static void	printChar( std::string const & input);
	static void	printInt( std::string const & input);
	static void	printFloat( std::string const & input);
	static void	printDouble( std::string const & input);

	template <typename T>
    static void convert(std::string const & input) {
		if (typeid(T) == typeid(char))
			printChar( input );
		else if (typeid(T) == typeid(int))
			printInt( input );
		else if (typeid(T) == typeid(float))
			printFloat( input );
		else if (typeid(T) == typeid(double))
			printDouble( input );
		else
			std::cerr << "Unknown type" << std::endl;
	}
};

