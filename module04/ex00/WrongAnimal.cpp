/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:18:29 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 16:31:30 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("WrongAnimal")
{
}

WrongAnimal::WrongAnimal( std::string type ) : _type(type)
{
}

WrongAnimal::WrongAnimal( const WrongAnimal& other) : _type(other._type)
{
}

WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& other )
{
	this->_type = other._type;
	return *this;
}

WrongAnimal::~WrongAnimal( void )
{
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
	std::cout << "(Sound of the form of a WrongAnimal)" << std::endl;
}
