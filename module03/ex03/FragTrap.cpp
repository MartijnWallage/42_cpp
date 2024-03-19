/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:52:54 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 14:39:50 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap("No-one")
{
    _hitPoints = 100;
	_energyPoints = 100;
    _attackDamage = 30;
	std::cout << "Anonymous FragTrap " << _name << " is constructed." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " is constructed." << std::endl;
}

FragTrap::FragTrap( const FragTrap& other ) : ClapTrap(other._name)
{
	*this = other;
	std::cout << "A clone of FragTrap " << _name << " is constructed." << std::endl;
}

FragTrap&	FragTrap::operator=( const FragTrap& other )
{
	std::cout << "FragTrap " << _name;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << " is now a clone of FragTrap " << _name << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " is destroyed." << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		this->_energyPoints--;
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    } else {
		std::cout << "FragTrap " << _name << " has no energy or hit points left!" << std::endl;
	}
}

void FragTrap::highFiveGuys() {
	std::cout << "FragTrap " << _name << " would like to politely make a positive request for a high five." << std::endl;
}