/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:25:22 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/25 15:48:12 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	std::cout << "Cat constructed" << std::endl;
}

Cat::Cat( const Cat& ) : Animal("Cat")
{
	std::cout << "Cat copy constructed" << std::endl;
}

Cat&	Cat::operator=( const Cat& other )
{
	_type = other._type;
	std::cout << "Cat copy assigned" << std::endl;
	return *this;
}

Cat::~Cat( void )
{
	std::cout << "Cat destructed" << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Cat goes meow!!" << std::endl;
}
