/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:25:22 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 16:33:34 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
}

Cat::Cat( const Cat& ) : Animal("Cat")
{
}

Cat&	Cat::operator=( const Cat& other )
{
	_type = other._type;
	return *this;
}

Cat::~Cat( void )
{
}

void	Cat::makeSound( void ) const
{
	std::cout << "Cat goes meow!!" << std::endl;
}
