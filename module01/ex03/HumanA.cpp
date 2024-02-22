/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:20:26 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/22 14:20:27 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA( std::string newName, Weapon& myWeapon) : name(newName), weapon(myWeapon) {}

void	HumanA::attack( void ) const {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}