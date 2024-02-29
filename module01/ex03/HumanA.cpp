/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:20:26 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/29 15:01:18 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA( std::string newName, Weapon& myWeapon)
	: _name(newName), _weapon(myWeapon) {}

void	HumanA::attack( void ) const {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}