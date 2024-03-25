/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:29:31 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/25 15:50:10 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog"), _brain(new Brain)
{
	std::cout << "Dog is created" << std::endl;
}

Dog::Dog( const Dog& other ) : Animal("Dog")
{
	if (other._brain) {
		_brain = new Brain(*other._brain);
	} else {
		_brain = NULL;
	}
	std::cout << "Dog is copied" << std::endl;
}

Dog&	Dog::operator=( const Dog& other )
{
	if (this != &other) {
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
		std::cout << "This dog is now the same as the other dog" << std::endl;
	} else {
		std::cout << "These dogs were already one and the same dog" << std::endl;
	}
	return *this;
}

Dog::~Dog( void )
{
	delete _brain;
	std::cout << "Dog died" << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Dog goes woof!!" << std::endl;
}

Brain*	Dog::getBrain( void ) const
{
	std::cout << "Returning brain " << _brain << std::endl;
	return _brain;
}