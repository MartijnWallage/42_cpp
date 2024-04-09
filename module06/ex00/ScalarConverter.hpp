/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:36:45 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/09 17:54:19 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <stdexcept>

class ScalarConverter {
	private:
		ScalarConverter( void );
		ScalarConverter( ScalarConverter const & );
		ScalarConverter & operator=( ScalarConverter const &);
		~ScalarConverter( void );
	public:
		static void convert( std::string const literal );
};
