/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:52:54 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/18 16:48:54 by mwallage         ###   ########.fr       */
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