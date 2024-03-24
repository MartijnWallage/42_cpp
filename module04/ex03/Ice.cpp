/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:53:51 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/24 21:05:27 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice( void ) : AMateria("ice")
{
	std::cout << "Ice constructed!" << std::endl;
}

Ice::Ice( Ice const& other ) : AMateria(other.getType())
{
	std::cout << "Ice copied!" << std::endl;
}

Ice& Ice::operator=( Ice const& )
{
	std::cout << "Ice assigned to another!" << std::endl;
	return (*this);
}

Ice::~Ice( void )
{
	std::cout << "Ice destructed!" << std::endl;
}

Ice* Ice::clone() const
{
	Ice *ret = new Ice;
	return ret;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
