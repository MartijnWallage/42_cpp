/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:25:22 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 16:33:34 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
}

WrongCat::WrongCat( const WrongCat& ) : WrongAnimal("WrongCat")
{
}

WrongCat&	WrongCat::operator=( const WrongCat& other )
{
	_type = other._type;
	return *this;
}

WrongCat::~WrongCat( void )
{
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "WrongCat goes meow!!" << std::endl;
}
