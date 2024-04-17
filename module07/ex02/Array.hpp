/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:19:25 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/17 16:12:38 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
	private:
		T*				_data;
		unsigned int	_arrayLen;

	public:
		Array() : _data(NULL), _arrayLen(0) {
			std::cout << "Array of size " << _arrayLen << " constructed" << std::endl;
		}

		Array( unsigned int n ) : _data( new T[n] ), _arrayLen( n ) {
			std::cout << "Array of size " << _arrayLen << " constructed" << std::endl;
			for (unsigned int i = 0; i < _arrayLen; i++) {
				_data[i] = T();
				std::cout << "Array[" << i << "] = " << _data[i] << std::endl;
			}
		}

		Array( Array const & other ) : _data( new T[other._arrayLen]), _arrayLen(other._arrayLen) {
			for (unsigned int i = 0; i < _arrayLen; i++) {
				_data[i] = other._data[i];
				std::cout << "Array[" << i << "] = " << _data[i] << std::endl;
			}
		}
		
		Array & operator=( Array const & other ) {
			if (this != &other) {
				delete[] _data;
				_arrayLen = other._arrayLen;
				_data = new T[_arrayLen];
				for (unsigned int i = 0; i < _arrayLen; i++) {
					_data[i] = other._data[i];
					std::cout << "Array[" << i << "] = " << _data[i] << std::endl;
				}
			}
			return *this;
		}

		T & operator[]( unsigned int i ) {
			if (i >= _arrayLen)
				throw std::out_of_range("Index out of bounds");
			return _data[i];
		}

		T const & operator[]( unsigned int i ) const {
			if (i >= _arrayLen)
				throw std::out_of_range("Index out of bounds");
			return _data[i];
		}

		~Array( void ) { 
			delete[] _data;
			std::cout << "Array destroyed" << std::endl;
		}

		unsigned int	size( void ) const { return _arrayLen; }
		
};
