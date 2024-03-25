/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:18:29 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/25 15:04:25 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("WrongAnimal")
{
	std::cout << "Generic WrongAnimal constructed" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : _type(type)
{
	std::cout << "WrongAnimal of type " << _type << " constructed" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& other) : _type(other._type)
{
	std::cout << "WrongAnimal of type " << _type << " copy-constructed" << std::endl;	
}

WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& other )
{
	this->_type = other._type;
	return *this;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal of type " << _type << " destructed" << std::endl;
}

std::string	WrongAnimal::getType( void ) const
{
	return _type;
}

void	WrongAnimal::setType( std::string type)
{
	_type = type;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "(Sound of a WrongAnimal qua WrongAnimal)" << std::endl;
}
