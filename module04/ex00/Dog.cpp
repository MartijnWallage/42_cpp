/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:29:31 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/25 15:49:00 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
	std::cout << "Dog constructed" << std::endl;
}

Dog::Dog( const Dog& ) : Animal("Dog")
{
	std::cout << "Dog copy constructed" << std::endl;
}

Dog&	Dog::operator=( const Dog& other )
{
	_type = other._type;
	std::cout << "Dog copy assigned" << std::endl;
	return *this;
}

Dog::~Dog( void )
{
	std::cout << "Dog destructed" << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Dog goes woof!!" << std::endl;
}

