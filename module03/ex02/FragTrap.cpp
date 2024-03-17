/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:52:54 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/17 18:06:57 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " is constructed." << std::endl;
}

FragTrap::~FragTrap() {
        std::cout << "ScavTrap " << _name << " is destroyed." << std::endl;
}

void FragTrap::attack(const std::string& target) {
        std::cout << "ScavTrap " << _name << " attacks " << target << " with a pie, causing " << _attackDamage << " points of damage!" << std::endl;
    }

void FragTrap::guardGate() {
        std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
    }