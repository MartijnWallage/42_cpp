/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:18:29 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/25 15:01:37 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Animal.hpp"

Animal::Animal( void ) : _type("Animal")
{
	std::cout << "Generic Animal constructed" << std::endl;
}

Animal::Animal( std::string type ) : _type(type)
{
	std::cout << "Animal of type " << _type << " constructed" << std::endl;
}

Animal::Animal( const Animal& other) : _type(other._type)
{
	std::cout << "Animal of type " << _type << " copy-constructed" << std::endl;
}

Animal&	Animal::operator=( const Animal& other )
{
	this->_type = other._type;
	return *this;
}

Animal::~Animal( void )
{
	std::cout << "Animal of type " << _type << " destructed" << std::endl;
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
	std::cout << "(Sound of an animal qua animal)" << std::endl;
}
