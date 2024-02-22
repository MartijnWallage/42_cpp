/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:21:52 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/22 14:21:53 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed( void ) : value( 0 ){

	std::cout << "Default constructor called" << std::endl;

}

Fixed::Fixed( const Fixed& obj ) {

	std::cout << "Copy constructor called" << std::endl;
	*this = obj;

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

