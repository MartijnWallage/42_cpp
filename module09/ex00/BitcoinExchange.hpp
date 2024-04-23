/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:37:51 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/23 16:57:23 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstdlib>
#include <utility>
#include <stdexcept>

class BitcoinExchange {
	public:
		BitcoinExchange( char const & filename);
		BitcoinExchange( BitcoinExchange const & );
		BitcoinExchange & operator=( BitcoinExchange const &);
		~BitcoinExchange();

		void compute() const;
	private:
		std::map<std::string, float> _dataMap;
		std::map<std::string, float> & _parseData();

		class BadFileException : public std::exception {
			virtual const char* what() const throw();
		};
		class TooLargeNumberException : public std::exception {
			virtual const char* what() const throw();
		};
		
		class BadInputException : public std::exception {
			virtual const char* what() const throw();
		};

		class BadDataException : public std::exception {
			virtual const char* what() const throw();
		};

		class NotPositiveNumberException : public std::exception {
			virtual const char* what() const throw();
		};
};
