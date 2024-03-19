/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:29:31 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 17:09:16 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
	_brain = new Brain;
}

Dog::Dog( const Dog& other ) : Animal("Dog")
{
	_brain = new Brain(*other._brain);
}

Dog&	Dog::operator=( const Dog& other )
{
	_type = other._type;
	*_brain = *other._brain;
	return *this;
}

Dog::~Dog( void )
{
	delete _brain;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Dog goes woof!!" << std::endl;
}

