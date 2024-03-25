/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:25:22 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/25 15:49:43 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat( void ) : Animal("Cat"), _brain(new Brain)
{
	std::cout << "Cat is created" << std::endl;
}

Cat::Cat( const Cat& other ) : Animal("Cat")
{
	if (other._brain) {
		_brain = new Brain(*other._brain);
	} else {
		_brain = NULL;
	}
	std::cout << "Cat is copied" << std::endl;
}

Cat&	Cat::operator=( const Cat& other )
{
	if (this != &other) {
		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
		std::cout << "This cat is now the same as the other cat" << std::endl;
	} else {
		std::cout << "These cats were already one and the same cat" << std::endl;
	}
	return *this;
}

Cat::~Cat( void )
{
	delete _brain;
	std::cout << "Cat died" << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Cat goes meow!!" << std::endl;
}

Brain*	Cat::getBrain( void ) const
{
	std::cout << "Returning brain " << _brain << std::endl;
	return _brain;
}
