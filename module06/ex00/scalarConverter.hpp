/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:36:45 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/13 19:45:45 by mwallage         ###   ########.fr       */
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
#include <iomanip>

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

    static void convert(std::string const & input);
};

