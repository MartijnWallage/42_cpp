/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:18:29 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 16:31:30 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Animal.hpp"

Animal::Animal( void ) : _type("Animal")
{
}

Animal::Animal( std::string type ) : _type(type)
{
}

Animal::Animal( const Animal& other) : _type(other._type)
{
}

Animal&	Animal::operator=( const Animal& other )
{
	this->_type = other._type;
	return *this;
}

Animal::~Animal( void )
{
}

std::string	Animal::getType( void ) const
{
	return _type;
}

void	Animal::setType( std::string type)
{
	_type = type;
}

void	Animal::makeSound( void ) const
{
	std::cout << "(Sound of the form of an animal)" << std::endl;
}
