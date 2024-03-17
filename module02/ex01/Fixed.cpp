/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:22:08 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/17 15:18:01 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) : _value( 0 ) {

	std::cout << "Default constructor called" << std::endl;

}

Fixed::Fixed( const Fixed& obj ) {

	std::cout << "Copy constructor called" << std::endl;
	*this = obj;

}

Fixed::Fixed( const int intValue ) {

	std::cout << "Int constructor called" << std::endl;
	this->_value = intValue << _fracSize;

}

Fixed::Fixed( const float floatValue ) {

	std::cout << "Float constructor called" << std::endl;
	int		intPart = static_cast<int>(roundf(floatValue));
	float	fracPart = floatValue - intPart;
	int		fixedFracPart = static_cast<int>(roundf(fracPart * 256));

	_value = (intPart << 8) | (fixedFracPart);
}

float	Fixed::toFloat( void ) const {

	return 	static_cast<float>(_value) / (1 << _fracSize);

}

int		Fixed::toInt( void ) const {

	return _value >> 8;
}

Fixed& Fixed::operator=( const Fixed& other ) {

	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = other._value;

	return *this;
}

Fixed::~Fixed( void ) {

	std::cout << "Destructor called" << std::endl;

}
	
int		Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called" << std::endl;

	return (_value);
}

void	Fixed::setRawBits( int const raw ) {

	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;

}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {

	os << obj.toFloat();

	return (os);
}