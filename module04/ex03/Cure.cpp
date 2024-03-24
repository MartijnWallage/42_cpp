/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:44:30 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/24 21:05:19 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure")
{
	std::cout << "Cure constructed!" << std::endl;
}

Cure::Cure( Cure const& other ) : AMateria(other.getType())
{
	std::cout << "Cure copied!" << std::endl;
}

Cure& Cure::operator=( Cure const& )
{
	std::cout << "Cure assigned to another!" << std::endl;
	return (*this);
}

Cure::~Cure( void )
{
	std::cout << "Cure destructed!" << std::endl;
}

Cure* Cure::clone() const
{
	Cure *ret = new Cure;
	return ret;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
