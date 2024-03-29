/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:52:54 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 14:34:36 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap("No-one")
{
    _hitPoints = 100;
	_energyPoints = 50;
    _attackDamage = 20;
	std::cout << "Anonymous ScavTrap " << _name << " is constructed." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " is constructed." << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& other ) : ClapTrap(other._name)
{
	*this = other;
	std::cout << "A clone of ScavTrap " << _name << " is constructed." << std::endl;
}

ScavTrap&	ScavTrap::operator=( const ScavTrap& other )
{
	std::cout << "ScavTrap " << _name;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << " is now a clone of ScavTrap " << _name << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " is destroyed." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		this->_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    } else {
		std::cout << "ScavTrap " << _name << " has no energy or hit points left!" << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}