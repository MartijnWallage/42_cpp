/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:53:31 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/24 17:40:09 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("Materia")
{
	std::cout << "AMateria constructed!" << std::endl;
}

AMateria::AMateria( std::string const & type ) : _type(type)
{
	std::cout << "AMateria of type " << _type << " constructed!" << std::endl;
}

AMateria::AMateria( AMateria const& other ) : _type(other._type)
{
	std::cout << "AMateria of type " << _type << " copied!" << std::endl;
}

AMateria&	AMateria::operator=( AMateria const& other )
{
	std::cout << "AMaterias assigned to another!" << std::endl;
	return *this;
}

AMateria::~AMateria( void ) {
	std::cout << "AMateria destructed!" << std::endl;
}

std::string const & AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "AMateria used on " << target.getName() << std::endl;
}
