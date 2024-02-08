
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

Fixed::~Fixed( void ) {

	std::cout << "Destructor called" << std::endl;

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