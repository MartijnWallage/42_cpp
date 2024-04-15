/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:36:45 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/15 16:00:21 by mwallage         ###   ########.fr       */
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

class ScalarConverter {
private:
    ScalarConverter();
	ScalarConverter( ScalarConverter const & );
	ScalarConverter& operator=( ScalarConverter const &);
	~ScalarConverter();

public:
	
	static bool 	isChar( std::string const & input );
	static bool 	isInt( std::string const & input );
	static bool 	isFloat( std::string const & input );
	static bool 	isDouble( std::string const & input );

	static char		convertChar( std::string const & input);
	static int		convertInt( std::string const & input);
	static float	convertFloat( std::string const & input);
	static double	convertDouble( std::string const & input);

	static void		printTable( const char c );
	static void 	printTable( const int n );
	static void 	printTable( const float f );
	static void 	printTable( const double d );

    static void		convert(std::string const & input);

	class ConversionFailException : public std::exception {
		virtual const char* what() const throw();
	};

	class EmptyInputException : public std::exception {
		virtual const char* what() const throw();
	};

	class UnknownTypeException : public std::exception {
		virtual const char* what() const throw();
	};
};

