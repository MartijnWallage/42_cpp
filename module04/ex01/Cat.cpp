/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:25:22 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 17:08:38 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	_brain = new Brain;
}

Cat::Cat( const Cat& other ) : Animal("Cat")
{
	this->_brain = new Brain(*other._brain);
}

Cat&	Cat::operator=( const Cat& other )
{
	_type = other._type;
	*_brain = *other._brain;
	return *this;
}

Cat::~Cat( void )
{
	delete _brain;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Cat goes meow!!" << std::endl;
}
