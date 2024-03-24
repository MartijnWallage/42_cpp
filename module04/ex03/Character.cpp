/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:53:42 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/24 18:17:56 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"

Character::Character( void ) : _name("")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Nameless Character constructed!" << std::endl;
}

Character::Character( std::string const name ) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character " << _name << " constructed!" << std::endl;
}

Character::Character( Character const& other ) : _name(other._name)
{
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
		_inventory[i] = other._inventory[i];
	}
	std::cout << "Character " << _name << " copied!" << std::endl;
}

Character& Character::operator=( Character const& other )
{
	_name = other._name;
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
		_inventory[i] = other._inventory[i];
	}
	std::cout << "Character " << _name << " assignment copied!" << std::endl;
	return *this;
}

Character::~Character( void )
{
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
	}
	std::cout << "Character " << _name << " destructed" << std::endl;
}

std::string const & Character::getName()
{
	return _name;
}

void Character::equip( AMateria* m)
{
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			std::cout << "Character equiped with AMateria of type "
				<< m->getType() << std::endl;
			return ;
		};
	}
	std::cout << "Inventory is already full!" << std::endl;
}

void Character::unequip( int idx )
{
	if (idx < 0 || idx > 3) {
		std::cout << "Invalid index!" << std::endl;
		return ;
	}
	if (_inventory[idx]) {
		std::cout << "AMateria of type "
			<< _inventory[idx]->getType() << " removed!" << std::endl;
		_inventory[idx] = NULL;
	} else {
		std::cout << "_inventory[" << idx << "] was already empty!" << std::endl;
	}
}

void Character::use( int idx, ICharacter& target )
{
	if (idx < 0 || idx > 3) {
		std::cout << "Invalid index!" << std::endl;
	} else if (_inventory[idx] == NULL) {
		std::cout << "_inventory[" << idx << "] is empty!" << std::endl;
	} else {
		_inventory[idx]->use(target);
	}
}
