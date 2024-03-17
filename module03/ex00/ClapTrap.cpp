/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:53:20 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/17 17:50:38 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " is constructed." << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap " << _name << " is destructed." << std::endl;
}

void	ClapTrap::attack(std::string& target)
{
	if (this->_energyPoints > 0) {
		this->_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target;
		std::cout << ", causing " << 10 << " points of damage!" << std::endl;
	}
	else {
		std::cout << "ClapTrap " << _name << " has no energy points left!" << std::endl;
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
	if (_energyPoints > 0) {
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " is repaired with ";
		std::cout << amount << " of hitpoints." << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " has no energy left!";
	}
}