/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:53:20 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 14:32:54 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("No-one"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap No-one is constructed." << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " is constructed." << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& other )
{
	*this = other;
	std::cout << "A clone of ClapTrap " << _name << " is constructed." << std::endl;
}

ClapTrap&	ClapTrap::operator=( const ClapTrap& other )
{
	std::cout << "ClapTrap " << _name;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << " is now a clone of ClapTrap " << _name << std::endl;
	return *this;
}

void	ClapTrap::setName( const std::string& name )
{
	std::cout << "ClapTrap " << _name << " renamed " << name << std::endl;
	this->_name = name;
}

std::string	ClapTrap::getName( void ) const
{
	return _name;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap " << _name << " is destructed." << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		this->_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target;
		std::cout << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else {
		std::cout << "ClapTrap " << _name << " has no energy points or hit points left!" << std::endl;
	}
}
	
void	ClapTrap::takeDamage(unsigned int amount)
{
	_attackDamage += amount;
	std::cout << "ClapTrap " << _name << " takes " << amount;
	std::cout << " points of damage." << std::endl;	
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0) {
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " is repaired with ";
		std::cout << amount << " of hitpoints." << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " has no energy or hit points left!";
	}
}