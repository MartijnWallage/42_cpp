/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:52:54 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/18 14:56:07 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap()
{
	_name = "No-one";
	std::cout << "Anonymous DiamondTrap " << _name << " is constructed." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	_name = name;
	std::cout << "DiamondTrap " << _name << " is constructed." << std::endl;
}

void	DiamondTrap::setName( std::string name)
{
	_name = name;
}

std::string	DiamondTrap::getName( void ) const
{
	return _name;
}

void	DiamondTrap::displayPoints( void ) const
{
	this->whoAmI();
	std::cout << "Hit points: " << _hitPoints << std::endl;
	std::cout << "Energy points: " << _energyPoints << std::endl;
	std::cout << "Attack damage: " << _attackDamage << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " is destroyed." << std::endl;
}

void DiamondTrap::whoAmI() const
{
	std::cout << "I am ClapTrap " << ClapTrap::_name << " and ";
	std::cout << "I am DiamondTrap " << _name << std::endl;
}