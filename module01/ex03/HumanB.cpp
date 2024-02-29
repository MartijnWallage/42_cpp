/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:20:36 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/29 15:03:39 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( std::string newName ) : _weapon(NULL), _name(newName) {}


void	HumanB::setWeapon( Weapon& newWeapon ) {
	this->_weapon = &newWeapon;
}

void	HumanB::attack( void ) const {
	if (this->_weapon) {
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	}
	else
		std::cout << this->_name << " has no weapon!" << std::endl;
}
