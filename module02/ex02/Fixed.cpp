/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:22:46 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/24 16:31:12 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) : value( 0 ) {

	std::cout << "Default constructor called" << std::endl;

}

Fixed::Fixed( const Fixed& obj ) {

	std::cout << "Copy constructor called" << std::endl;
	*this = obj;

}

Fixed::Fixed( const int intValue ) {

	std::cout << "Int constructor called" << std::endl;
	this->value = intValue << fracSize;

}

Fixed::Fixed( const float floatValue ) {

	std::cout << "Float constructor called" << std::endl;
	int		intPart = static_cast<int>(roundf(floatValue));
	float	fracPart = floatValue - intPart;
	int		fixedFracPart = static_cast<int>(roundf(fracPart * 256));

	value = (intPart << 8) | (fixedFracPart);
}

Fixed::~Fixed( void ) {

	std::cout << "Destructor called" << std::endl;

}

float	Fixed::toFloat( void ) const {

	return 	static_cast<float>(value) / (1 << fracSize);

}

int		Fixed::toInt( void ) const {

	return value >> 8;
}

Fixed& Fixed::operator=( const Fixed& other ) {

	std::cout << "Copy assignment operator called" << std::endl;
	this->value = other.value;

	return *this;
}

bool	Fixed::operator>( const Fixed& other ) const {
	return value > other.value;
}

bool	Fixed::operator<( const Fixed& other ) const {
	return value < other.value;
}

bool	Fixed::operator>=( const Fixed& other ) const {
	return value >= other.value;
}

bool	Fixed::operator<=( const Fixed& other ) const {
	return value <= other.value;
}

bool	Fixed::operator==( const Fixed& other ) const {
	return value == other.value;
}

bool	Fixed::operator!=( const Fixed& other ) const {
	return value != other.value;
}

Fixed	Fixed::operator+( const Fixed& other ) const {
	return Fixed(value + other.value);
}

Fixed	Fixed::operator-( const Fixed& other ) const {
	return Fixed(value - other.value);
}

Fixed	Fixed::operator*( const Fixed& other ) const {
	return (this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/( const Fixed& other ) const {
	int32_t	overflow = (value / other.value);
	int		result = overflow * (1 << 16);
	return Fixed(result);
}

Fixed&	Fixed::operator++( void ) {
	++value;
	return *this;
}

Fixed	Fixed::operator++( int ){
	Fixed	temp;

	temp.value = value++;
	return temp;
}

Fixed&	Fixed::operator--( void ) {
	--value;
	return *this;
}

Fixed	Fixed::operator--( int ) {
	Fixed	temp;

	temp.value = value--;
	return temp;

}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {

	return a.value < b.value ? a : b;

}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {

	return a.value > b.value ? a : b;

}

const Fixed&	Fixed::min(Fixed& a, Fixed& b) {

	return a.value < b.value ? a : b;

}

const Fixed&	Fixed::max(Fixed& a, Fixed& b) {

	return a.value > b.value ? a : b;

}

int		Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called" << std::endl;

	return (value);
}

void	Fixed::setRawBits( int const raw ) {

	std::cout << "setRawBits member function called" << std::endl;
	value = raw;

}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {

	os << obj.toFloat();

	return (os);
}