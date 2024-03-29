/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:18:15 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/25 13:12:25 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	std::cout << "MateriaSource constructed!" << std::endl;
}

MateriaSource::MateriaSource( MateriaSource const& other ) : IMateriaSource()
{
	for (int i = 0; i < 4; i++) {
		_inventory[i] = other._inventory[i];
	}
	std::cout << "MateriaSource copied!" << std::endl;
}

MateriaSource& MateriaSource::operator=( MateriaSource const& other )
{
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
		_inventory[i] = other._inventory[i];
	}
	std::cout << "MateriaSource assignment copied!" << std::endl;
	return *this;
}
	
MateriaSource::~MateriaSource( void )
{
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
	}
	std::cout << "MateriaSource destructed!" << std::endl;
}

void MateriaSource::learnMateria( AMateria* other )
{
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = other;
			std::cout << "AMateria of type " << other->getType() << " learned!" << std::endl;
			return ;
		}
	}
	std::cout << "Full of knowledge, cannot learn anymore!" << std::endl;
}

AMateria* MateriaSource::createMateria( std::string const & type )
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] && _inventory[i]->getType() == type) {
			std::cout << "AMateria of type " << _inventory[i]->getType() << " cloned!" << std::endl;
			return (_inventory[i]->clone());
		}
	}
	std::cout << "Invalid type! Cannot create materia." << std::endl;
	return (0);
}
