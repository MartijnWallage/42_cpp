#include "Fixed.hpp"

Fixed::Fixed() : number(0){};

Fixed::Fixed(int orig) : number(orig) {

}

Fixed& Fixed::operator=(const Fixed& other) {
		number = other.number;
	}

Fixed::~Fixed() {};
	
int		Fixed::getRawBits( void ) const {

}

void	Fixed::setRawBits( int const raw ) {

}