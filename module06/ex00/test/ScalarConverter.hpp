/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:36:45 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/12 19:11:20 by mwallage         ###   ########.fr       */
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

class ScalarConverter {
private:
    ScalarConverter();
	ScalarConverter( ScalarConverter const & );
	ScalarConverter& operator=( ScalarConverter const &);

public:
	~ScalarConverter();
	
	static void	printChar( std::string const & input);
	static void	printInt( std::string const & input);
	static void	printFloat( std::string const & input);
	static void	printDouble( std::string const & input);

	template <typename T>
    static void convert(std::string const & input)
	{
		if (typeid(T) == typeid(char))
			printChar( input );
		else if (typeid(T) == typeid(int))
			printInt( input );
		else if (typeid(T) == typeid(float))
			printFloat( input );
		else if (typeid(T) == typeid(double))
			printDouble( input );
		else
			std::cerr << "Unkown type" << std::endl;
	}
};

