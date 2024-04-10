/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:36:45 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/10 17:45:21 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include <cstdlib> // For std::atoi and std::atof
#include <cfloat> // For FLT_MAX, DBL_MAX
#include <climits> // For INT_MAX

enum scalarType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	OTHER	
};

class ScalarConverter {
	private:
		static std::string & 	_str;
		static scalarType		_type;
		ScalarConverter( void );
		ScalarConverter( ScalarConverter const & );

		static bool isSpecialFloat(const std::string& str);
 	  	static bool isSpecialDouble(const std::string& str);
		static bool	isChar( void );
		static std::string	getCharValue( void );
		static std::string	getIntValue( void );
		static std::string	getFloatValue( void );
		static std::string	getDoubleValue( void );
	public:
		ScalarConverter & operator=( ScalarConverter const &);
		~ScalarConverter( void );
		static void convert( std::string const str );
};
