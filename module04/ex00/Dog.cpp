/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:29:31 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 16:33:13 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
}

Dog::Dog( const Dog& ) : Animal("Dog")
{
}

Dog&	Dog::operator=( const Dog& other )
{
	_type = other._type;
	return *this;
}

Dog::~Dog( void )
{
}

void	Dog::makeSound( void ) const
{
	std::cout << "Dog goes woof!!" << std::endl;
}

