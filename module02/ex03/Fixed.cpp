/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:22:46 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/14 16:32:37 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) : _value( 0 ) 
{
}

Fixed::Fixed( const Fixed& obj ) 
{
	*this = obj;
}

Fixed::Fixed( const int intValue ) 
{
	this->_value = intValue << _fracSize;
}

Fixed::Fixed( const float floatValue )
{
	this->_value = (roundf)(floatValue * pow(2, _fracSize));
}

Fixed::~Fixed( void ) 
{
}

float	Fixed::toFloat( void ) const {

	return (static_cast<float>(_value) / (1 << _fracSize));

}

int		Fixed::toInt( void ) const {

	return _value >> _fracSize;
}

Fixed& Fixed::operator=( const Fixed& other ) 
{
	if (this != &other) {
		this->_value = other._value;
	}
	return *this;
}

bool	Fixed::operator>( const Fixed& other ) const
{
	return _value > other._value;
}

bool	Fixed::operator<( const Fixed& other ) const
{
	return _value < other._value;
}

bool	Fixed::operator>=( const Fixed& other ) const
{
	return _value >= other._value;
}

bool	Fixed::operator<=( const Fixed& other ) const
{
	return _value <= other._value;
}

bool	Fixed::operator==( const Fixed& other ) const
{
	return _value == other._value;
}

bool	Fixed::operator!=( const Fixed& other ) const
{
	return _value != other._value;
}

Fixed	Fixed::operator+( const Fixed& other ) const
{
	return Fixed(_value + other._value);
}

Fixed	Fixed::operator-( const Fixed& other ) const
{
	return Fixed(_value - other._value);
}

Fixed	Fixed::operator*( const Fixed& other ) const
{
	return (this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/( const Fixed& other ) const
{
	return (this->toFloat() / other.toFloat());
}

Fixed&	Fixed::operator++( void )
{
	++this->_value;
	return *this;
}

Fixed	Fixed::operator++( int )
{
	Fixed	temp;

	temp._value = this->_value++;
	return temp;
}

Fixed&	Fixed::operator--( void )
{
	--this->_value;
	return *this;
}

Fixed	Fixed::operator--( int )
{
	Fixed	temp;

	temp._value = this->_value--;
	return temp;

}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return a._value < b._value ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return a._value > b._value ? a : b;
}

const Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return a._value < b._value ? a : b;
}

const Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return a._value > b._value ? a : b;
}

int		Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}
