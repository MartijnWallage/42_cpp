/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:25:22 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/25 15:43:01 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructed" << std::endl;
}

WrongCat::WrongCat( const WrongCat& ) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat copy constructed" << std::endl;
}

WrongCat&	WrongCat::operator=( const WrongCat& other )
{
	std::cout << "WrongCat copy assigned" << std::endl;
	_type = other._type;
	return *this;
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat destructed" << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "WrongCat goes meow!!" << std::endl;
}
